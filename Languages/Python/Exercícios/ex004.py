n1 = input('Digite algo:')
print('O tipo primitivo desse valor é' , type(n1))
print('Só tem espaços?' , n1.isspace())
print('É um número?' , n1.isnumeric())
print('É alfabético?', n1.isalpha())
print('É alfanumérico?' , n1.isalnum())
print('Está em maiúsculas?' , n1.isupper())
print('Está em minúsulas?' , n1.islower()) 
print('Está capitalizado?' , n1.istitle())

#se eu colocar um espaço na hora de digitar ele para de contar como alfabético
