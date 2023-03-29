m = float(input('Digite aqui uma medida em metros:'))
km = m / 1000
hm = m / 100
dam = m/ 10
dm = m * 10
cm = m * 100
mm = m * 1000
# km hm dam m dm cm mm
print(f'A medida de {m} metros corresponde a:')
print('=' * 15)
print(f'{km} km \n {hm} hm \n {dam} dam \n {dm} dm \n {cm} cm \n {mm} mm ')
print('=' * 15)