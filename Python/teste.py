from random import randint

# Função para printar o tabuleiro
def print_tabuleiro(tab): 
  print('  1 2 3 4 5 6')
  print('  -----------')
  numero_da_fileira = 1
  for fileira in tab:
    print('%d|%s|' % (numero_da_fileira, '|'.join(fileira)))
    numero_da_fileira += 1

def marcar_tabuleiro(x,y,n,coin,tabuleiro):
  if coin == 1:
    for i in range(x,x+n):
      tabuleiro[y][i] = 'X'
  else:
    for i in range(x,x+n):
      tabuleiro[i][y] = 'X'

def verifica(x,n,coin,tabuleiro): 
  if coin == 1:
    for i in range(0,6):
      if tabuleiro[x][i] == 'X':
        return False
  else:
    for i in range(0,6):
      if tabuleiro[x][i] == 'X':
        return False
  return True

def criar_navios(tabuleiro):
  coin = randint(0,1)
  # Porta avioes
  x = randint(0,1)
  y = randint(0,5)
  marcar_tabuleiro(x,y,5,coin,tabuleiro)
  # Navio tanque
  while True:
    x = randint(0,2)
    y = randint(0,5)
    if verifica(y,4,coin,tabuleiro):
      break
  marcar_tabuleiro(x,y,4,coin,tabuleiro)
  # Controtorpedeiro
  while True:
    x = randint(0,3)
    y = randint(0,5)
    if verifica(y,3,coin,tabuleiro):
      break
  marcar_tabuleiro(x,y,3,coin,tabuleiro)
  # Submarino
  while True:
    x = randint(0,4)
    y = randint(0,5)
    if verifica(y,2,coin,tabuleiro):
      break
  marcar_tabuleiro(x,y,2,coin,tabuleiro)
  

borda = [[' ']*6 for x in range(6)]
borda_escondida = [[' ']*6 for x in range(6)]

criar_navios(borda)
print_tabuleiro(borda)