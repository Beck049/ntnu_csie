print("Please enter an unsigned 16-bits number: ")
num = int(input())
print("Before Flip:")

print(num, "_10 = ", hex(num), "_16" )

len = len(hex(num));

out = []
for i in range(len-2):
    out.append(hex(num)[len-i-1])

num = 0
for i in range(len-2):
    num += int(out[i]) * pow(16, len-3-i)

print("After  Flip:")
print(num, "_10 = 0x", end = "")
for i in range(len-2):
    print(out[i], end = "")
print("_16")