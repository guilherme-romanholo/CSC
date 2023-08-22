import math
cat1 = float(input('Digite o valor do cateto oposto:'))
cat2 = float(input('Digite o valor do cateto adjacente:'))
hip = math.hypot(cat1 , cat2)
print(f'A hipotenusa vai medir {hip}.')