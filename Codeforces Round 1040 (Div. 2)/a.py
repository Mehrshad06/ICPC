t = int(input())
for _ in range(t):
    n = int(input())
    q = list(map(int, input().split()))
    w = 0
    for num in q:
        if num != 0:
            w += num
        else:
            w += 1
    print(w)
