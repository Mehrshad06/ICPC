n, t = map(int, input().split())
a = [0] * (n + 2)
b = [0] * (n + 2)


for i in range(1, n + 1):
    a[i] = int(input())
    b[i] = b[i - 1] + a[i]


mm = -1
mom = -1
ghm = [0] * (n + 2)
bam = [0] * (n + 2)
q = [0] * (n + 2)


for i in range(1, n + 1):
    if a[i] > mm:
        mm = a[i]
        mom = i
    ghm[i] = b[mom - 1]
    bam[i] = b[i] - b[mom]
    q[i] = mm


for i in range(1, n + 1):
    w = t - (ghm[i] + bam[i])
    kp = max(1, (w // q[i]) + 1) if w >= 0 else 1
    print(kp)
