# TODO
def main():
    cents = get_cents()
    cents = round(int(cents *100))
    coins = 0
    while cents > 0:
        if cents >= 25:
            cents = cents - 25
            coins = coins + 1
        elif cents >= 10:
            cents = cents - 10
            coins = coins + 1
        elif cents >= 5:
            cents = cents - 5
            coins = coins + 1
        elif cents >= 1:
            cents = cents - 1
            coins = coins + 1

    print(coins)


def get_cents():
    while True:
        try:
            n = float(input("No. of Cents: "))
            if n > 0:
                break
        except ValueError:
            print("That's not a valid number!")
    return n

main()
