# TODO
def main():
    height = get_height()
    for i in range(height):
        print(" ",end="")
        for j in range(height):
            print("#", end="")

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