import sys
sys.setrecursionlimit(1500)

def bubble_sort(arr: list) -> list:
    n = len(arr)
    for i in range(0, n - 1):
        for j in range(0, n - i - 1):
            if (arr[j] > arr[j + 1]):
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

    return arr

def selection_sort(arr: list) -> list:
    n = len(arr)
    for i in range(0, n - 1):
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j

        if min_idx != i:
            arr[i], arr[min_idx] = arr[min_idx], arr[i]

    return arr

def insertion_sort(arr: list) -> list:
    n = len(arr)
    for i in range(1, n):
        j = i
        while(j >= 1 and arr[j] < arr[j - 1]):
            arr[j - 1], arr[j] = arr[j], arr[j - 1]
            j -= 1

    return arr

def counting_sort(arr: list, c: int = 256) -> list:
    n = len(arr)
    out = [0 for i in range(n)]
    count = [0 for i in range(256)]

    for i in arr:
        count[i] += 1

    for i in range(1, c):
        count[i] += count[i - 1]

    for i in range(n - 1, -1, -1):
        out[count[arr[i]] - 1] = arr[i]
        count[arr[i]] -= 1

    for i in range(0, n):
        arr[i] = out[i]

    return arr

def merge_sort(arr: list) -> list:
    n = len(arr)

    def merge(low: int, mid: int, high: int) -> None:
        out = [0 for i in range(0, high - low + 1)]
        l = low
        r = mid + 1
        i = 0

        while l <= mid and r <= high:
            if arr[l] < arr[r]:
                out[i] = arr[l]
                i += 1
                l += 1

            else:
                out[i] = arr[r]
                i += 1
                r += 1

        while l <= mid:
            out[i] = arr[l]
            i += 1
            l += 1

        while r <= high:
            out[i] = arr[r]
            i += 1
            r += 1

        for i in range(low, high + 1):
            arr[i] = out[i - low]

    def sort(low: int, high: int) -> None:
        if low >= high: return
        mid = (high + low) // 2
        sort(low, mid)
        sort(mid + 1, high)
        merge(low, mid, high)

    sort(0, n-1)
    return arr

def quick_sort(arr: list) -> list:
    n = len(arr)

    def partition(low: int, high: int) -> int:
        i = low
        pivot = arr[high]

        #auxillary space for processing is between low -> high - 1
        for j in range(low, high):
            if arr[j] < pivot:
                 arr[i], arr[j] = arr[j], arr[i]
                 i += 1

        arr[i], arr[high] = arr[high], arr[i]
        return i

    def sort(low: int, high: int) -> None:
        if low >= high: return
        p_idx = partition(low, high)
        sort(low, p_idx - 1)
        sort(p_idx + 1, high)

    sort(0, n - 1)
    return arr


def heap_sort(arr: list) -> list:
    n = len(arr)

    def heapify(i: int, n: int) -> None:
        left = 2 * i + 1
        right = 2 * i + 2
        maxi = i

        if left < n  and arr[left] > arr[maxi]:
            maxi = left

        if right < n and arr[right] > arr[maxi]:
            maxi = right

        if maxi != i:
            arr[i], arr[maxi] = arr[maxi], arr[i]
            heapify(maxi, n)

    def sort() -> None:
        for i in range(n // 2 - 1, -1, -1):
            heapify(i, n)

        for i in range(n - 1,  0, -1):
            arr[0], arr[i] = arr[i], arr[0]
            heapify(0, i)

    sort()
    return arr

def radix_sort(arr: list) -> list:
    n = len(arr)

    def __counting_sort(exp: int) -> None:
        count = [0 for i in range(10)]
        out = [0 for i in range(n)]

        for i in arr:
            count[(i // exp) % 10] += 1

        for i in range(1, 10):
            count[i] += count[i - 1]

        #Not Stable
        # for i in arr:
        #     out[count[(i / exp) % 10]] = i
        #     count[(i / exp) % 10] -= 1

        #Stable
        for i in range(n - 1, -1, -1):
            out[count[(arr[i] // exp) % 10] - 1] = arr[i]
            count[(arr[i] // exp) % 10] -= 1

        for i in range(0, n):
            arr[i] = out[i]

    def sort() -> None:
        maxi = max(arr)
        exp = 1
        while(maxi / exp > 0):
            __counting_sort(exp)
            exp *= 10

    sort()
    return arr

def main():
    n = int(input())
    arr = list(map(int, input().split(" ")))
    assert n == len(arr)

    print(arr)
    print(radix_sort(arr))

main()
