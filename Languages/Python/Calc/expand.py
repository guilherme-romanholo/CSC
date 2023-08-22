from sympy import expand, symbols
x , y = symbols('x , y')
n = expand((x+y)**7)
print(n)
