print("v_0: ", end = " ")
v = float(input())
print("a: ", end = " ")
a = float(input())
print("t: ", end = " ")
t = float(input())

s = (v*t) + (a*t*t/2)
output = "--> s = {:.2f}"
print(output.format(s))