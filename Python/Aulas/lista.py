num = [1, 4, 6, 2]
num[2] = 3
num.append(7)
num.sort(reverse=True)
num.insert(2, 0) # 0 na posição 2
num.pop(5) # tira o elemento da posição 5
num.remove(2) # procura o numero 2 e remove ele
galera = [['João',19], ['Ana',22],['Maria',35]]
print(galera[0][0])
galera.clear()
for c in galera:
    print(c[0])
    print(c[1])
# quando iguala uma lista com a outra voce faz uma ligação de lista
# b = a[:] uma copia de a
# num = list()
print(num)
