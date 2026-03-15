t = int(input())
r = ['' for i in range(t)]
s = [['' for i in range(t)] for _ in range(100)]

for i in range(t):
    r[i], s[i] = input().split()
    r[i] = int(r[i])

for i in range(t):
    for j in range(len(s[i])):
        print(s[i][j]*r[i], end = '')
    print()