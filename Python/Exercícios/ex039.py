from datetime import date

nasc = int(input('Digite seu ano de nascimento:'))
ano = date.today().year
idade = ano - nasc

print(f'Quem nasceu em {nasc} tem {idade} anos em {ano}.')

if idade < 18:
    tempo = 18 - idade
    print(f'Você só precisa se alistar daqui {tempo} anos.')
elif idade > 18:
    tempo = idade - 18
    print(f'Você já deveria ter se alistado há {tempo} ano(s).')
elif idade == 18:
    print('Você tem 18 anos e deve se alistar imediatamente.')        
