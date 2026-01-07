def test_case():
    M, N = map(int, input().split())
    board = [0 for k in range(N)]
    for y in range(N):
        board[y] = list(map(int, input().split()))
    
    is_empty = True
    result_col_num = 0
    result_col_mul = 0
    for x in range(M):
        line_mul = 1
        for y in range(N):
            line_mul *= board[y][x]
        if is_empty:
            is_empty = False
            result_col_mul = line_mul
            result_col_num = x
        if result_col_mul <= line_mul:
            result_col_mul = line_mul
            result_col_num = x
    print(result_col_num + 1)

T = int(input())

for i in range(T):
    test_case()