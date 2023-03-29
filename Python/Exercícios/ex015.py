km = float(input('Qual a quantidade de km rodados com o carro?'))
dias = float(input('Qual a quantidade de dias que o carro foi utilizado?'))
preco = (60 * dias) + (0.15 * km)
print(f'O valor total a se pagar é R${preco:.2f}.') 