def calc(arr, k, n):
	for i in range(k):
		maxi = max(arr)
		arr[arr.index(maxi)] = maxi - 1

	print(arr)


def main():
	N = int(input())
	K = int(input())
	arr = []
	for i in range(N):
		arr.append(int(input()))

	print(calc(arr, K, N))

main()