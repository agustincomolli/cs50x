def main():
    print("*** Cadenas de texto ***\n")

    my_text = "   En AlgúN LUGAR de la mAncha   "
    print(f"- Texto original:\n{my_text}")

    my_text = my_text.strip()
    print(f"\n- Texto sin espacios:\n{my_text}")

    my_text = my_text.capitalize()
    print(f"\n- Texto capitalizado:\n{my_text}")

    my_text = my_text.upper()
    print(f"\n- Texto en mayúsculas:\n{my_text}")

    my_text = my_text.lower()
    print(f"\n- Texto en minúsculas:\n{my_text}")

    my_list = my_text.split()
    print(f"\n- Lista de palabras:\n{my_list}")

    print(f"\n- Slices:\n{my_text[3:8]}")


if __name__ == "__main__":
    main()
