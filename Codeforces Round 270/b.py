n, k = map(int, input().split())
q = list(map(int, input().split()))
q.sort(reverse=True) 
t = 0
for i in range(0, n, k):
    w = q[i]
    t += 2 * (w - 1)
print(t)
