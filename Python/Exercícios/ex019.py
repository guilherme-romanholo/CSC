from locale import ABDAY_1
from random import choice
a1 = str(input('Primeiro aluno:')) 
a2 = str(input('Segundo aluno:'))
a3 = str(input('Terceiro aluno:'))
a4 = str(input('Quarto aluno:'))
print(f'O aluno escolhido foi {choice([a1 , a2 , a3 , a4])}')
# em python uma lista fica entre colchetes[]
# eu poderia fazer da seguinte forma tambem

'''a1 = str(input('Primeiro aluno:')) 
a2 = str(input('Segundo aluno:'))
a3 = str(input('Terceiro aluno:'))
a4 = str(input('Quarto aluno:'))
lista = [a1 , a2, a3, a4]
print(choice(lista))        '''
