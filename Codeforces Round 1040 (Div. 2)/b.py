t = int(input())
for _ in range(t):
    n, s = map(int, input().split())
    a = list(map(int, input().split()))
    if s < sum(a):
        print(*a)
    elif s == sum(a) + 1:
        z = [0] * a.count(0)
        t = [2] * a.count(2)
        o = [1] * a.count(1)
        print(*(z + t + o))
    else:
        print(-1)
