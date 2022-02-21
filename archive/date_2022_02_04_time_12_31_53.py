def hasContinuosOnes(m, n):
    a = m
    b = n
    res = []
    for i in range(a + 1, b):
        binary = bin(i)
        if not "11" in binary:
            res.append(binary.replace("0b", ""))

    print("\n".join(res))


a = 5
b = 11

hasContinuosOnes(a, b)