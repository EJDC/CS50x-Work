# TODO

def main():
    word = get_string()
    print(word)


def get_string():
    while True:
        try:
            n = str(input("No. of Cents: "))
            if n > 0:
                break
        except ValueError:
            print("That's not a valid number!")
    return n

main()
