# TODO
def main():
    height = get_height()
    for i in range(height):
        for j in range(height):
            print(" " * (height - 1 - i), end="")
        for k in range(height):
            print("#" * (i + 1), end="")
        print("  ", end="")
        for m in range(height):
            print("#", end="")
        print()

def get_height():
    while True:
        try:
            n = int(input("Height: "))
            if n > 0:
                break
        except ValueError:
            print("That's not an integer!")
    return n

main()