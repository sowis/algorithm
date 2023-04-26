import sys

result = 0

lines = sys.stdin.readlines()
big_line = ''
for line in lines:
    big_line += line.strip()

for num in big_line.split(','):
    result += int(num)

print(result)