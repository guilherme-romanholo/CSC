num = int(input('Digite um número:'))
numd = num * 2
numt = num * 3
numr = num ** (1/2)
print(f'O dobro de {num} é igual a {numd}')
print(f'O triplo de {num} é igual a {numt}')
print(f'A raiz quadrada de {num} é igual a {numr:.3f}')
print('A raiz quadrada de {} é igual a {:.3f}' .format(num, numr))