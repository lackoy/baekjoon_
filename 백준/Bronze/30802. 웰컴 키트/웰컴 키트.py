n = int(input())
size = list(map(int,input().split()))
t, p = map(int,input().split())
score = 0
sum_score = 0

for i in range(len(size)):
    if (size[i]%t) == 0:
        score = size[i]//t
    else:
        score = size[i]//t + 1
    sum_score += score

print(sum_score)
print(n//p, n%p)