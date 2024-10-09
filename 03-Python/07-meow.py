def main():
    print("*** Mauyando 🐈 ***\n")

    meow(3)


def meow(amount: int = 1):
    for i in range(amount):
        print("Meow")


if __name__ == "__main__":
    main()
