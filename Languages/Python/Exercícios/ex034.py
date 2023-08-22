sal = float(input('Digite o salário do funcionário que precisa de aumento:'))

if sal <= 1250:
    aum = sal + (sal * 0.15)
else:
    aum = sal + (sal * 0.10)

print(f'Quem ganhava R${sal} passa a ganhar R${aum} agora.')    