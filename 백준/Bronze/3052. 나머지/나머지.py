a = [0 for i in range(10)]
b = [0 for i in range(1000)]

for i in range(10):
    a[i] = int(input())
    b[a[i]%42] = 1


print(sum(b))