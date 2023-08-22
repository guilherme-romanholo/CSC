casa = float(input('Digite o valor da casa: R$'))
sal = float(input('Digite o valor do seu salário: R$'))
ano = float(input('Digite em quantos anos você irá pagar:'))

mes = ano * 12
pago = casa / mes

print(f'Para pagar uma casa de {casa} em {ano} anos a prestação será de R${pago:.2f} ao mês.')

if pago > sal * 0.3:
    print('O seu empréstimo não pode ser aprovado, seu salário é muito baixo.')
else:
    print('Seu empréstimo foi aprovado!')    