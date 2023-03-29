# Uma varíavel aloca um espaço na memória que é dividido em micro espaços 

# Fatiamento de um string

frase = 'Teste de como funciona'
print(frase[0])
print(frase[14:21]) # ele vai do 14 ao 21 mas exclui o 21, o ultimo valor não entra na range
print(frase[0:22:2]) # ele vai contando de 2 em 2 e exclui o 2 
print(frase[:14]) # ele vai sempre buscar o caractere 0, lembrando que ele não pega o ultimo
print(frase[4:]) # ele vai ate o fim
print(frase[9::3]) # o final esta omitido e ele vai pular de 3 em 3

# nesse caso só sera printado o T que ocupa o microespaço 0, lembrando que os espaçamentos tambèm ocupam o "quadradinho"

