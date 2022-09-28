# TODO
def main():
    cents = get_cents()
    print(cents)


def get_cents():
    while True:
        n = float(input("No. of Cents:"))
        if n > 0:
             return n

main()
