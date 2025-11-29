from decimal import Decimal, getcontext

a, b = input().split()
getcontext().prec = 99999999
print("{0:f}".format(Decimal(a) ** int(b)))