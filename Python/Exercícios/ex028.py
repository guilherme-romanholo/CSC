from random import randint
from time import sleep
num1 = int(randint(0, 5))
num2 = int(input('Digite um número entre 0 e 5:'))
print('PROCESSANDO...')
sleep(3)
if num1 == num2:
    print('Parabéns, você acertou o número do computador!')
else:
    print('Você não acertou o número escolhido pelo computador, não foi dessa vez!')    
print(f'O número escolhido por você foi {num2} e o número escolhido pelo computador foi {num1}.')
