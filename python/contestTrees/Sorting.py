def heapify(arr, n, i):
    parent = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and arr[left] > arr[parent]:
        parent = left
    if right < n and arr[right] > arr[parent]:
        parent = right

    if parent != i:
        arr[i], arr[parent] = arr[parent], arr[i]
        heapify(arr, n, parent)

def heap_sort(arr):
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
    for i in range(n - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]

        heapify(arr, i, 0) 
    return arr


def merge(left_arr, right_arr):
    arr = []
    li = 0
    ri = 0

    while li < len(left_arr) and ri < len(right_arr):
        if left_arr[li] <= right_arr[ri]:
            arr.append(left_arr[li])
            li += 1
        else:
            arr.append(right_arr[ri])
            ri += 1

    while li < len(left_arr):
        arr.append(left_arr[li])
        li += 1
    while ri < len(right_arr):
        arr.append(right_arr[ri])
        ri += 1
    return arr

def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left_arr = merge_sort(arr[:mid])
    right_arr = merge_sort(arr[mid:])

    return merge(left_arr, right_arr)


def count_sort(arr):
    count_arr = [0] * (max(arr) + 1)
    for num in arr:
        count_arr[num] += 1
    
    for i in range(1, len(count_arr)):
        count_arr[i] += count_arr[i - 1]

    res_arr = [0] * len(arr)
    for i in range(len(arr) - 1, -1, -1):
        res_arr[count_arr[arr[i]] - 1] = arr[i]
        count_arr[arr[i]] -= 1

    return res_arr


def count_sort_for_radix(arr, exp):
    count_arr = [0] * 10
    for num in arr:
        index = (num // exp) % 10
        count_arr[index] += 1
    
    for i in range(1, 10):
        count_arr[i] += count_arr[i - 1]

    res_arr = [0] * len(arr)

    for i in range(len(arr) - 1, -1, -1):
        index = (arr[i] // exp) % 10
        res_arr[count_arr[index] - 1] = arr[i]
        count_arr[index] -= 1

    return res_arr

def radix_sort(arr):
    res_arr = arr
    max_num = max(res_arr)
    exp = 1
    while max_num // exp > 0:
        res_arr = count_sort_for_radix(res_arr, exp)
        exp *= 10
    return res_arr


def insertion_sort(arr):
    for i in range(1, len(arr)):
        value = arr[i]
        j = i - 1

        while j >= 0 and arr[j] > value:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = value

    return arr

arr = [9, 4, 3, 8, 10, 2, 5, 3, 1, 2, 2, 7] 
print(insertion_sort(arr))
