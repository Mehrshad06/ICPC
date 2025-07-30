n = int(input())
s = input().strip()

Ta = s.count('A')

Tb = s.count('B')
Tc = s.count('C')



def mamad(a, b, c, ta, tb, tc):
    ta = s.count(a);
    tb = s.count(b);
    tc = s.count(c);
    Re = float('inf')
    Ss = s + s
    Q_a = [0] * (2 * n + 1)
    Q_b = [0] * (2 * n + 1)
    Q_c = [0] * (2 * n + 1)
    for i in range(2 * n):
        Q_a[i+1] = Q_a[i] + (1 if Ss[i] == a else 0)
        Q_b[i+1] = Q_b[i] + (1 if Ss[i] == b else 0)
        Q_c[i+1] = Q_c[i] + (1 if Ss[i] == c else 0)
    
    for i in range(n):
        a_i = Q_a[i + ta] - Q_a[i]
        b_i = Q_b[i + ta + tb] - Q_b[i + ta]
        c_i = Q_c[i + n] - Q_c[i + ta + tb]
        Tt = a_i + b_i + c_i
        Re = min(Re, n - Tt)
        # if(Re == 1):
        #     print(a, b, c, i, i + ta, i + ta + tb, i + n, Q_a[i + ta], Q_a[i], Q_b[i + ta + tb], Q_b[i + ta], Q_c[i + n], Q_c[i + ta + tb] , a_i, b_i, c_i)
    return Re

end = float('inf')
for a, b, c in [('A', 'B', 'C'), ('A', 'C', 'B'), ('B', 'A', 'C'),
                ('B', 'C', 'A'), ('C', 'A', 'B'), ('C', 'B', 'A')]:
    Bo = mamad(a, b, c, Ta, Tb, Tc)
    end = min(end, Bo)


print(end)
