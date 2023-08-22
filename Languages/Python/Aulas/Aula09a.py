
# Análise

frase = 'Teste de como funciona'
print(len(frase)) # legth/comprimento numero de caracteres
print(frase.count('e')) # ele conta quantas tem na string
print(frase.count('e',0,4)) # lembrando que o 4 não é incluido
print(frase.find('ste')) # ele só fala em qual posição começou o ste
print(frase.find('android')) # recebe o valor -1 pra indicar que a string não existe
print('Curso' in frase) # vai retornar true ou false se encontrar a string na variavel
print('Teste' in frase)