import math

a, b, c, d = map(int, input().split())
s = (a + b + c + d) / 2
bb = math.sqrt((s - a) * (s - b) * (s - c) * (s - d))
print(bb)

