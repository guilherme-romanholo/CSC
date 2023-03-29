nota1 = float(input('Digite sua primeira nota:'))
nota2 = float(input('Digite sua segunda nota:'))
media = (nota1 + nota2) / 2

print(f'A sua média entre as notas é {media}.')

if media < 5:
    print('Você está REPROVADO!')
elif media > 5 and media < 7:
    print('Você está de RECUPERAÇÃO!')
elif media >= 7:
    print('Você está APROVADO!')       