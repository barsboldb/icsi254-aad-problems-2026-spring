N=[]
M=[]
T = int(input())

if T > 10 or T < 1:
    raise Exception("T must be 1 <= T <= 10")

for i in range(T):
    input_string = input()
    a, b = input_string.split(" ")
    a = int(a)
    b = int(b)
    if a > 1e9 or a < 3:
        raise Exception("N must be 3 <= N <= 10^9")
    if b > 1e9 or b < 0:
        raise Exception("M must be 0 <= M <= 10^9")
    N.append(a)
    M.append(b)


def cut_plane(n, m):
    if n-3 < m:
        return 0
    # combination for (n, 3)
    res = n*(n-1)*(n-2)//6
    return res

for i in range(T):
    res = cut_plane(N[i], M[i])
    print(res)