# TODO

def main():
    word = get_string()
    print(word)


def get_string():
    while True:
        try:
            n = str(input("Text: "))
            if len(str) > 1:
                break
        except ValueError:
            print("That's not a valid number!")
    return n

main()
