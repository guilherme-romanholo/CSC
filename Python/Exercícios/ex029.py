v = int(input('Digite a velocidade do seu carro em Km/h:'))
if v <= 80:
    print('Você está dentro do limite, dirija com segurança!')
else:
    multa = (v - 80) * 7
    print('Você ultrapassou o limite de velocidade que é 80km/h')
    print(f'Você pagará uma multa de R${multa}.')    