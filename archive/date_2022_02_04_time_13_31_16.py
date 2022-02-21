def calc(a, b):
    high = b // 2 + 1
    res = [0 for i in range(a, b + 1)]
    for i in range(2, high +1):
        for j in range(a, b + 1):
            if j % i == 0 and j != i:
                res[j - a] += 1

    low = 0
    high = 0
    arr = []
    for i in range(len(res)):
        if res[i] == 0:
            if(high - low + 1 > 5):
                arr.append(f"{low + a} {high + a} {high - low + 1}")
            low = i+1
            high = i
        else:
            high += 1

    print("\n".join(arr))
    
a = 50
b = 150
calc(a, b)