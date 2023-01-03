target = int(input())

cache = list()
cache.append(0)
cache.append(1)
for i in range(2, target + 1):
    cache.append(cache[i - 2] + cache[i - 1])

print(cache[target])