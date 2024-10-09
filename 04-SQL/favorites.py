from cs50 import SQL

data_base = SQL("sqlite:///favorites.db")

favorite = input("Favorito: ")

records = data_base.execute("SELECT COUNT(*) AS total FROM favorites WHERE problem = ?", favorite)

total_favorite = records[0]

print(f"Total: {total_favorite['total']}")
