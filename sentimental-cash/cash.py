# TODO
def main():
    cents = get_cents()
    print(cents)


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
