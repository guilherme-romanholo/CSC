
nome = str(input('Digite o seu nome completo:')).strip()





print(f'Seu nome em maíusculas é {nome.upper()}.')
print(f'Seu nome em minúsculas é {nome.lower()}.')
print('Seu nome tem um total de {} letras.'.format(len(nome) - nome.count(' ')))
print(f'Seu primeiro nome tem {len(nome.split()[0])} letras.')