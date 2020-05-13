# method1 - using extra variable
# swap

x,y = [int(inp) for inp in input("input for method 1: ").split()]

temp_var = x
x = y
y = temp_var
print(x, y)

# method2 - without using extra variable
# swap

x,y = [int(inp) for inp in input("input for method 1: ").split()]

x = x+y
y = x-y
x = x-y
print(x, y)
