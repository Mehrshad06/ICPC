n, m = map(int, input().split())
Q = []
for _ in range(n):
    p, c = map(int, input().split())
    Q.append((p, c))

low = 1
high = 2 * 10**15 

def is_p(t):
    tt = 0
    for p, c in Q:
        pp = p * t - c
        if pp > 0:
            tt += pp
            if tt >= m:
                return True
    return tt >= m

an = high
while low <= high:
    mid = (low + high) // 2
    if is_p(mid):
        an = mid
        high = mid - 1
    else:
        low = mid + 1

print(an)
