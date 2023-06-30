import sympy

x = sympy.symbols('x')
f = (x**3 + x**2 - x - 1)/(x**2 + 2*x + 1) 
n = sympy.simplify((x**3 + x**2 - x - 1)/(x**2 + 2*x + 1))

print('Função normal:')
print(f)
print('Função simplificada:')
print(n)
