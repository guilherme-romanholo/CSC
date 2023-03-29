# Importando a função para gerar inteiros aleatórios
from random import randint

# Declaração de variáveis globais para as cores
RED = '\033[1;31m'
BLUE = '\033[1;34m'
GREEN = '\033[32m'
RESET = '\033[0;0m'


# Função para printar o tabuleiro
def print_tabuleiro(tab):
    print('    1 2 3 4 5 6')
    print('   ------------')
    numero_da_fileira = 1
    # Laço para percorrer a matriz
    for i in range(0, 6):
        # Imprime o numero da fileira
        print(numero_da_fileira, '|', end=" ")
        numero_da_fileira += 1
        for j in range(0, 6):
            # Condições para imprimir a matriz colorida
            if tab[i][j] == 'X':
                print(RED + tab[i][j] + RESET, end=" ")
            elif tab[i][j] == '-':
                print(BLUE + tab[i][j] + RESET, end=" ")
            else:
                print(tab[i][j], end=" ")
        # Print para quebrar a liha
        print()


def ponto_valido(lin, col, n, coin, tab):
    # Verifica se o navio vai ser posicionado na vertical ou horizontal
    if coin == 1:
        # Verifica se o ponto é valido para posicionar
        for i in range(lin, lin+n):
            # Caso ele quebre alguma condição ele retorna falso
            if i < 0 or i > 5 or tab[i][col] != '0':
                return False
    else:
        # Verifica se o ponto é valido para posicionar
        for i in range(col, col+n):
            # Caso ele quebre alguma condição ele retorna falso
            if i < 0 or i > 5 or tab[lin][i] != '0':
                return False
    # Se não, retornamos verdadeiro
    return True


# Função para posicionar o navio na matriz
def posicionar_navio(lin, col, n, coin, tab):
    # Verifica se é na vertical ou horizontal
    if coin == 1:
        # Coloca o elemento colorido na matriz
        for i in range(lin, lin+n):
            tab[i][col] = GREEN + str(n) + RESET
    else:
        # Coloca o elemento colorido na matriz
        for i in range(col, col+n):
            tab[lin][i] = GREEN + str(n) + RESET



# Função para gerar navios aleatórios
def navios_aleatorios(tab, n):
    # Gera o número para sabermos se vai ser na horizontal ou vertical
    coin = randint(0, 1)
    # Posição do navio aleatória enquanto não acharmos uma posição válida
    while True:
        lin = randint(0, 5)
        col = randint(0, 5)
        if ponto_valido(lin, col, n, coin, tab):
            break
    # Quando acharmos, posicionamos o navio
    posicionar_navio(lin, col, n, coin, tab)


# Função para o posicionamento manual dos navios do jogador
def local_navio(tab):
    # Controla o tamanho do navio
    i = 5
    f = False
    # Posicionamos o navio no tabuleiro
    while True:
        print_tabuleiro(tab)
        # Validação do ponto digitado
        while True:
            print('Por favor digite uma posição válida')
            lin = int(input(f'LINHA de inicio para o navio de {i} espaços: '))
            col = int(input(f'COLUNA de inicio para o navio de {i} espaços: '))
            vert_hor = int(input('Posicionamento: [0]Horizontal [1]Vertical: '))
            if ponto_valido(lin-1, col-1, i, vert_hor, tab) and (str(vert_hor) in '01'):
              break
        # Posicionamento na matriz
        posicionar_navio(lin-1, col-1, i, vert_hor, tab)
        # Passamos para o navio com tamanho menor
        i -= 1
        # Verficação de quando vamos parar o laço
        # Após o posicionamento do segundo submarino
        if f:
            break
        if i == 1:
            i += 1
            f = True


# Verifica a posição atacada pelo jogador
def verifica_ataque_jogador(tab, tab_esc, lin, col):
    # Caso a posição já foi atacada anteriormente
    if tab_esc[lin][col] == 'X':
        return False
    # Caso a posição possua alguma embarcação
    if tab[lin][col] not in '0-':
        tab_esc[lin][col] = 'X'
        return True
    # Caso a posição não possua nenhuma embarcação
    else:
        tab_esc[lin][col] = '-'
        tab[lin][col] = '-'
        return False


def verifica_ataque_bot(tab, lin, col):
    # Caso a posição já foi atacada anteriormente
    if tab[lin][col] == 'X':
        return False
    # Caso a posição possua alguma embarcação
    if tab[lin][col] not in '0-':
        tab[lin][col] = 'X'
        return True
    # Caso a posição não possua nenhuma embarcação
    else:
        tab[lin][col] = '-'
        return False


# Função principal
def main():
    # Tabuleiro com os navios do bot
    tabuleiro_bot = [['0']*6 for x in range(6)]
    # Tabuleiro do bot que vai aparecer para o jogador
    tabuleiro_bot_escondido = [['0']*6 for x in range(6)]
    # Tabuleiro do jogador
    tabuleiro_jogador = [['0']*6 for x in range(6)]
    # Embarcações afundadas
    player = 0
    bot = 0

    # Gerar as embarações aleatórias para o bot
    navios_aleatorios(tabuleiro_bot, 5)
    navios_aleatorios(tabuleiro_bot, 4)
    navios_aleatorios(tabuleiro_bot, 3)
    navios_aleatorios(tabuleiro_bot, 2)
    navios_aleatorios(tabuleiro_bot, 2)
    # Posicionamento das embarcações do jogador
    local_navio(tabuleiro_jogador)
    # Quebra de linha
    print()

    # Enquanto alguem não venceu
    while True:
        # Verifica se alguem já venceu o jogo
        if player == 16:
            print(BLUE + 'Jogador venceu!' + RESET)
            break
        if bot == 16:
            print(BLUE + 'Bot venceu!' + RESET)
            break
        # Mostra os tabuleiros
        print('Seu tabuleiro: ')
        print_tabuleiro(tabuleiro_jogador)
        print('Tabuleiro do bot ')
        print_tabuleiro(tabuleiro_bot_escondido)
        # Recebe uma posição para ser atacada pelo jogador
        lin = int(input('Digite a LINHA para o ataque: '))
        col = int(input('Digite a COLUNA para o ataque: '))
        # Quebra de linha
        print()
        # Faz a verificação se o ataque foi efetivo
        if verifica_ataque_jogador(tabuleiro_bot, tabuleiro_bot_escondido, lin-1, col-1):
            print('\nJogador ' + BLUE + 'acertou!' + RESET)
            player += 1
        else:
            print('Jogador ' + RED + 'errou!' + RESET)
        # Posição aleatória de ataque para o bot
        lin = randint(0, 5)
        col = randint(0, 5)
        # verifica se o ataque do bot foi efetivo
        if verifica_ataque_bot(tabuleiro_jogador, lin-1, col-1):
            print('Bot ' + BLUE + 'acertou!' + RESET)
            bot += 1
        else:
            print('Bot ' + RED + 'errou!' + RESET)
        # Quebra de linha
        print()

    # Printa os tabuleiro após o final do jogo
    print('Seu tabuleiro: ')
    print_tabuleiro(tabuleiro_jogador)
    print('\nTabuleiro do Bot: ')
    print_tabuleiro(tabuleiro_bot)


# Utilizado para a declaração da função main()
if __name__ == "__main__":
  main()
