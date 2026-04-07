for i in range(0, 3):
    N = int(input())
    cur_sum = 0
    
    for k in range(N):
        cur_sum += int(input())

    if cur_sum < 0:
        print('-')
    elif cur_sum == 0:
        print(0)
    else:
        print('+')