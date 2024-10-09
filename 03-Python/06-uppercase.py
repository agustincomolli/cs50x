def my_upper(text:str) -> str:
    upper_text = ""
    for char in text:
        upper_text += char.upper()
    return upper_text


def other_upper(text:str) -> str:
    for char in text:
        print(char.upper(), end="")
    print()

print("*** Convirtiendo texto a MAYUSCULAS ***\n")
some_text = input("Antes:   ")
print(f"Después: {some_text.upper()}")
print(f"Después: {my_upper(some_text)}")
print(f"Después: ", end="")
other_upper(some_text)
