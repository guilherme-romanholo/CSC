palavra = str(input("Digite uma palavra: ")).strip().lower()
partes = palavra.split()
junto = ''.join(partes)
inverso = ''
for c in range(len(junto) - 1, -1, -1):
    inverso += junto[c]
if inverso == junto:
    print("É palíndromo")
else:
    print("Não é palíndromo")
