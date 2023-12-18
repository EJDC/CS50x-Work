import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash
from datetime import datetime


from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

    """Get user's cash balance"""
    user_cash = get_user_cash(session["user_id"])

    """Get user's stock holdings and relevant information"""
    user_portfolio = get_user_portfolio(session["user_id"])

    """Calculate total value of each holding and the grand total"""
    total_value = calculate_portfolio_value(user_portfolio, user_cash)

    return render_template(
        "index.html", portfolio=user_portfolio, cash=user_cash, total_value=total_value
    )


"""Function to get user's cash balance from the database"""
def get_user_cash(user_id):
    cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
    return round(cash[0]["cash"],2) if cash else 0


"""Function to get user's stock portfolio from the database"""
def get_user_portfolio(user_id):
    user_portfolio = db.execute("SELECT * FROM portfolios WHERE user_id = ?", user_id)
    return user_portfolio


""" Function to calculate the total value of the user's portfolio """
def calculate_portfolio_value(portfolio, cash):
    total_value = cash  # Start with the cash balance

    for item in portfolio:
        # Assuming you have a function to get the current price of a stock from an API
        stock = lookup(item["symbol"])
        print(stock)
        if stock is not None:
            total_value += stock["price"] * int(item["no_of_shares"])

    return round(total_value,2)

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """If the user is trying to buy a quote"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        no_of_shares = request.form.get("shares")

        """ Ensure inputs are not blank """
        if not symbol or not no_of_shares:
            flash("Stock symbol and number of shares are required", "error")
            return apology("Stock symbol and number of shares are required")

        """ Ensure input number of shares is a positive integer """
        if not no_of_shares.isdigit() or int(no_of_shares) <= 0:
            flash("Number of shares must be a positive integer", "error")
            return apology("Number of shares must be a positive integer")

        """ Get stock price """
        stock_data = lookup(symbol)

        """ Ensure Stock Symbol exists """
        if stock_data is None:
            flash("Stock symbol does not exist", "error")
            return apology("Stock symbol does not exist")

        """ Calculate total cost  """
        total_cost = stock_data["price"] * int(no_of_shares)

        """ Get the user's cash  """
        user_id = session["user_id"]
        user_cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        user_cash = user_cash[0]["cash"]

        """ Check if user has enough cash for purchase  """
        if total_cost > user_cash:
            flash("Not Enough Cash!", "error")
            return apology("Not Enough Cash!")

        """ Perform purchase (Update user's cash and record purchase in the database) """
        updated_user_cash = user_cash - total_cost
        db.execute("UPDATE users SET cash = ? WHERE id = ?", updated_user_cash, user_id)

        """ Add transaction to portfolio database """
        db.execute(
            "INSERT INTO portfolios (user_id, name, symbol, no_of_shares, paid_price, current_price, date, total_cost) VALUES (?, ?, ?, ?, ?, ?, ?, ?)",
            user_id,
            stock_data["name"],
            symbol,
            no_of_shares,
            round(stock_data["price"], 2),
            round(stock_data["price"], 2),
            datetime.now().strftime("%d-%m-%Y %H:%M:%S"),
            round(total_cost, 2),
        )

        """ Add transaction to history database """
        db.execute(
            "INSERT INTO history (user_id, name, symbol, no_of_shares, type, date) VALUES (?, ?, ?, ?, ?, ?)",
            user_id,
            stock_data["name"],
            symbol,
            no_of_shares,
            "PURCHASED",
            datetime.now().strftime("%d-%m-%Y %H:%M:%S"),
        )

        flash("Purchase successful!", "success")
        return redirect("/")

    return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """If the user is trying to get a quote"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        """If the price is retrieved successfully, render the quoted.html template"""
        data = lookup(symbol)
        if data is not None:
            data["price"] = usd(data["price"])
            return render_template("quoted.html", data=data)
        else:
            return apology("Invalid symbol!")

    """User got here via GET so render the page"""
    return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form["username"]
        unhashed_password = request.form["password"]
        confirmation = request.form["confirmation"]

        """Check if username or password or confirmation don't exist"""
        if not username or not unhashed_password or not confirmation:
            flash("Did not complete all fields!", "error")
            return apology("Did not complete all fields!")

        """Check if password and confirmation don't match"""
        if unhashed_password != confirmation:
            flash("Passwords do not match!", "error")
            return apology("Passwords do not match!")

        """Check if username already exists"""

        def username_exists(username):
            result = db.execute(
                "SELECT * FROM users WHERE username = :username", username=username
            )
            return len(result) > 0

        if username_exists(username):
            flash("Username already exists cannot register!. Please login.", "error")
            return apology("Username already exists cannot register!")

        """Hash password and save to database"""
        hash = generate_password_hash(unhashed_password)
        db.execute("INSERT INTO users (username, hash) VALUES(%s, %s)", username, hash)
        flash("Registration successful!", "success")
        return render_template("login.html")

    else:
        """User got here via GET so render the page"""
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock."""
    user_id = session["user_id"]
    portfolio = db.execute("SELECT * FROM portfolios WHERE user_id = ?", user_id)

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        symbol = request.form.get("symbol")
        stock = lookup(symbol)
        shares = int(request.form.get("shares"))

        owned_stock = db.execute(
            "SELECT shares FROM portfolios WHERE user_id = ? AND symbol = ?",
            user_id,
            symbol,
        )

        # Check if user owns shares of the stock
        if not owned_stock:
            return apology(f"You don't own any shares of {symbol}!")

        # Check if user has enough shares to sell
        current_shares = sum([stock["shares"] for stock in owned_stock])
        if current_shares < shares:
            return apology("You don't have enough shares to sell!")

        # Retrieve user's balance
        cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)
        cash = cash[0]["cash"]
        # Deposit value of sold shares
        current_price = stock["price"]
        cash += shares * current_price

        # Perform the sale
        for info in owned_stock:
            # Update database if user sells less shares than the total amount he owns
            if info["shares"] > shares:
                db.execute(
                    "UPDATE portfolios SET shares = ? WHERE user_id = ? AND symbol = ?",
                    info["shares"] - shares,
                    user_id,
                    symbol,
                )
            # Delete stock from portfolio if all shares were sold
            else:
                db.execute(
                    "DELETE FROM portfolios WHERE user_id = ? AND symbol = ?",
                    user_id,
                    symbol,
                )

        # Format balance
        balance = f"${cash:,.2f} (+${(shares * current_price):,.2f})"

        # Update user's cash balance
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash, user_id)

        # Add transaction to history database
        db.execute(
            "INSERT INTO history (user_id, name, symbol, shares, action, balance, date) VALUES (?, ?, ?, ?, ?, ?, ?)",
            user_id,
            stock["name"],
            symbol,
            shares,
            "SOLD",
            balance,
            get_time(),
        )

        flash(f"Successfully sold {shares} shares of {symbol}!")
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    return render_template("sell.html", portfolio=portfolio)

