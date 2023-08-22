
dist = float(input('Digite a distância em km da viagem:'))

if dist <= 200:
    preco = dist * 0.50
else: 
    preco = dist * 0.45

print(f'Você fez uma vigem de {dist} km, portanto o preço cobrado será de R${preco}.')