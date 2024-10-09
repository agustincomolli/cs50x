def main():
    greeting = input("Saludo: ")
    greeting = greeting.strip()
    if "hello" in greeting.lower():
        print("$0")
    elif greeting[0].lower() == "h":
        print("$20")
    else:
        print("$100")


if __name__ == "__main__":
    main()
