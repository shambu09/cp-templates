def heapify(heap, i, n):
    maxi = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and heap[maxi] < heap[left]:
        maxi = left

    if right < n and heap[maxi] < heap[right]:
        maxi = right

    if maxi != i:
        heap[maxi], heap[i] = heap[i], heap[maxi]
        heapify(heap, maxi, n)

def max_heap(n, heap):
    tmp = n // 2 - 1

    for i in range(tmp, -1, -1):
        heapify(heap, i, n)

    return heap         


class Solution:
    def maxProfit(self, inventory: list, orders: int) -> int:
        n = len(inventory)
        heap = max_heap(n, inventory)
        profit = 0
        tmp = 0
        for i in range(0, orders):
            profit += heap[0]
            profit = profit % (1e9 + 7)
            heap[0] -= 1
            # if n != 1:
            #     heapify(heapeap, 0, n)
        
        return profit


arr = list(map(int, input().split(" ")))
k = int(input())

s = Solution()  
print(s.maxProfit(arr, k))

            