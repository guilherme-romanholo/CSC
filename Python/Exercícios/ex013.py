sal1 = float(input('Qual é o salário do funcionário? R$:'))
aumento = int(input('Insira a porcentagem do aumento do salário:'))
sal2 = sal1 + (aumento / 100 * sal1 )
print(f'Um funcionário que ganhava R${sal1}, com um aumento de {aumento}%, passa a receber R${sal2:.2f}. ')