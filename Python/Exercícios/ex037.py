num = int(input('Digite um número inteiro:'))
print(''' Escolha uma das bases para a conversão:
[ 1 ] Binário
[ 2 ] Octal
[ 3 ] Hexadecimal''')

escolha = int(input('Sua opção:'))

if escolha == 1:
    print(f'A conversão de {num} para binário é {bin(num)[2:]}.')
elif escolha == 2:
    print(f'A conversão de {num} para octal é {oct(num)[2:]}.')
elif escolha == 3:
    print(f'A conversão de {num} para hexadecimal é {hex(num)[2:]}.')     
else:
    print('Opção inválida, tente novamente!')
