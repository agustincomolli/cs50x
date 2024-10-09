def main():
    names = ["Agustín", "Lorena", "Adrián"]

    to_search = input("Nombre: ")

    if to_search in names:
        print("¡Encontrado!")
    else:
        print("No se ha encontrado ese nombre")

    # Lista de 3 diccionarios.
    contacts = [
        {"name": "Agustín", "phone": "(2226)-680056"},
        {"name": "Lorena", "phone": "(11)-58836722"},
        {"name": "Adrián", "phone": "(2664)-838076"}
    ]

    to_search = input("Nombre: ")
    for contact in contacts:
        if to_search == contact["name"]:
            print(f"Teléfono: {contact["phone"]}")
            break
    else:
        print("No sea encontrado el contacto.")

    # Usando un solo diccionario.
    contacts = {
        "Agustín" : "(2226)-680056",
        "Lorena" : "(11)-58836722",
        "Adrián" : "(2664)-838076"
    }

    to_search = input("Nombre: ")

    if to_search in contacts:
        print(f"Teléfono: {contacts[to_search]}")
    else:
        print("No se ha encontrado el contacto.")


if __name__ == "__main__":
    main()
