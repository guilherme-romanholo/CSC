import math
ang = float(input('Digite o ângulo que você deseja:'))
sen = math.sin(math.radians(ang))
cos = math.cos(math.radians(ang))
tan = math.tan(math.radians(ang))  
print(f'O angulo {ang} tem o SENO de {sen:.2f}.')
print(f'O angulo {ang} tem o COSSENO de {cos:.2f}.')
print(f'O angulo {ang} tem o TANGENTE de {tan:.2f}.')
# para o seno, cosseno e tangente funcionarem é necessário transformar em radianos antes