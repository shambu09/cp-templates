def reverseString(input1):
    return " ".join(input1.split(" ")[::-1])

k = input()
print(reverseString(k))