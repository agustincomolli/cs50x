print("\n*** Acuerdo de Licencia de Usuario Final ***\n")
print("Este Acuerdo es un contrato legal entre usted  y yo para el uso de este software.\n")
# Poner la entrada en minúsculas.
answer = input("¿Está de acuerdo con los términos del contrato? ").lower()

if answer in ["s", "si", "sí"]:
    print("😀 Estás de acuerdo")
elif answer in ["n", "no"]:
    print("😢 No estás de acuerdo")
else:
    print("🤔 Humm... No te entendí")
