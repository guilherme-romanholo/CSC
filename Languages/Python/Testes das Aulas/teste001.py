n1 = int(input('Digite um número:')) 
n2 = int(input('Digite outro número:'))
s = n1 + n2
#print('A soma entre' , n1 , 'e' , n2 , 'é igual a' , s )
print('A soma entre {0} e {1} vale {2}' .format(n1, n2, s))


# .isnumeric ele fala se pode ser um número
# .isalpha ele fala se pode ser uma letra, alfabético
# .isalnum ele fala se é alfabético e numérico
# .isupper ele fala se só ta em caps
# .islower ele fala se só ta minúsculo