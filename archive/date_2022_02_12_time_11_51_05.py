"""
input:
2
3 3
1 2 4
1 3 4
3 2
1 2 3
2 3

output:
3
1
"""
def largest_rectangle(n, m, a, b):
    memo = {}
    for i in a:
        memo[i] = memo.get(i, 0) + (i + 0.5)

    for i in b:
        memo[i] = memo.get(i, 0) - (i + 0.5)

    idx = 0.5
    maxArea = 0
    for i in memo:
        if idx == 0.5 and memo[i] == 0:
            idx = i

        elif memo[i] == 0:
            maxArea = max(maxArea, i - idx)

    return maxArea

T = int(input())
for _ in range(T):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    out_ = largest_rectangle(n, m, a, b)
    print(out_)
