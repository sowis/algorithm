f = []

input = int(input())
f.append(0)
f.append(1)
for i in range(2, input + 1):
    f.append(f[i -2] + f[i - 1])

print(f[input])