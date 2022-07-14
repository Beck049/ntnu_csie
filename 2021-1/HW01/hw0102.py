x = 123;
print("Please enter the first  number: ");
a = int(input());
print("Please enter the second number: ");
b = int(input());
c = a+b

def get_digits(num):
    cnt = 0
    while(num != 0):
        num = int(num/10)
        cnt = cnt+1
    return cnt

len = 0;
if(a >= b):
    len = get_digits(a)
else:
    len = get_digits(b)

print(len)
print(get_digits(b))

def split(num, len):
    dig = get_digits(num)
    for i in range(len-dig):
        print(" ", end = " ")
    for i in range(dig):
        print(int(num/(10**(dig-1-i))), end = " ")
        num %= 10**(dig-1-i)

print("\n  ", end = " ")
split(a, len)
print("\n+)", end = " ")
split(b, len)
print(" ")
for i in range(len):
    print("--", end = "-")
print(" ")
if( get_digits(c) == len ):
    print("  ", end = " ")
    split(c, len)
else:
    print(" ", end = " ")
    split(c, len+1)
print(" ")