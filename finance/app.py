import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

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
    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    return apology("TODO")


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
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
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
    if request.method == 'POST':
        symbol = request.form.get('symbol')
        price = lookup(symbol)
        if price is not None:
            # If the price is retrieved successfully, render the quoted.html template
            return render_template('quoted.html', symbol=symbol, price=price)
        else:
            # Handle case where stock symbol is invalid or price retrieval fails
            return apology("Invalid symbol!")

    """User got here via GET so render the page"""
    return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == 'POST':
        username = request.form['username']
        unhashed_password = request.form['password']
        confirmation = request.form['confirmation']

        """Check if username or password or confirmation don't exist"""
        if not username or not unhashed_password or not confirmation:
            flash('Did not complete all fields!', 'error')
            return apology("Did not complete all fields!")

        """Check if password and confirmation don't match"""
        if unhashed_password != confirmation:
            flash('Passwords do not match!', 'error')
            return apology("Passwords do not match!")

        """Check if username already exists"""
        def username_exists(username):
            result = db.execute("SELECT * FROM users WHERE username = :username", username=username)
            return len(result) > 0
        if username_exists(username):
            flash('Username already exists cannot register!. Please login.', 'error')
            return apology("Username already exists cannot register!")

        """Hash password and save to database"""
        hash = generate_password_hash(unhashed_password)
        db.execute("INSERT INTO users (username, hash) VALUES(%s, %s)", username, hash)
        flash('Registration successful!', 'success')
        return render_template("login.html")

    else:
        """User got here via GET so render the page"""
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
