def brute(n):
    if n <= 9:
        return str(n)

    else:
        for i in range(n, 9, -1):
            arr = []
            for a, b in zip(str(i)[0: n - 1], str(i)[1:]):
                arr.append(abs(int(a) - int(b)) == 1)

            if(all(arr)):
                return str(i)
                break


def bfs(n):
    def _bfs(x, n): 
        q = []
        q.append(x)
        res = 0

        while (len(q) != 0):
            num = q.pop(0)
            if(num <= n):
                res = max(res, num)
                s = num % 10
                if s == 0:
                    q.append(num * 10 + 1)
                
                elif s == 9:
                    q.append(num * 10 + 8)
                
                else:
                    q.append(num * 10 + s + 1)
                    q.append(num * 10 + s - 1)
        return res

    res = 0
    for i in range(1, 10):
        res = max(res, _bfs(i, n))

    return str(res)


def test_brute():
    for i in range(1, 10000):
        brute(i)

def test_bfs():
    for i in range(1, 10000):
        bfs(i)

#-----------------------------------------------------------#

import timeit

num_runs = 1
duration = timeit.Timer(test_brute).timeit(number = num_runs)
avg_duration = duration/num_runs
print(f'On average bruteforce took {avg_duration} seconds')


num_runs = 1
duration = timeit.Timer(test_bfs).timeit(number = num_runs)
avg_duration = duration/num_runs
print(f'On average bfs took {avg_duration} seconds')