def maxarray(cls, input1, input2):
    sum = 0
    maxsum = input2[0]

    for i in input2:
        sum += i
        maxsum = max(maxsum, sum)
        if sum < 0:
            sum = 0

    return maxsum

one = int(input())
two = list(map(int, input().split(" ")))
print(two)
print(maxarray(one, two))