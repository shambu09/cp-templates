"""
input:
1
5
1 5 2 3 4

output:
12
"""
def solve(N, a):
    res = 0
    for i in range(N - 1, 0, -1):
        if a[i] < a[i - 1]:
            a[i - 1]  -= (a[i - 1] - a[i])
        res += a[i]

    return res + a[0]



T = int(input())
for _ in range(T):
    N = int(input())
    a = list(map(int, input().split()))

    out_ = solve(N, a)
    print(out_)
