# 2 metros quadrados de parede precisam de 1 litro de tinta para ser pintado
larg = float(input('Digite a largura da sua parede:'))
alt = float(input('Digite a altura da sua parede:'))
area = larg * alt
tinta = area / 2
print(f'Sua parede tem a dimensão {larg} x {alt} e sua área é de {area}m².' )
print(f'Para pintar essa parede serão necessários {tinta} L de tinta.')