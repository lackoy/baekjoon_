n = input()
for i in range(len(n)):
    if 'a' <= n[i] <= 'z': print(n[i].upper(), end = '')
    else: print(n[i].lower(), end = '')