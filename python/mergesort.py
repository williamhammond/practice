def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left_array = arr[:mid]
        right_array = arr[mid:]

        merge_sort(left_array)
        merge_sort(right_array)

        i = j = k = 0
        while i < len(left_array) and j < len(right_array):
            if left_array[i] < right_array[j]:
                arr[k] = left_array[i]
                i += 1
            else:
                arr[k] = right_array[j]
                j += 1
            k += 1
        while i < len(left_array):
            arr[k] = left_array[i]
            i += 1
            k += 1
        while j < len(right_array):
            arr[k] = right_array[j]
            j += 1
            k += 1

def merge_sort_2(arr):
    if len(arr > 1):
        mid = len(arr) // 2
        left_array = arr[:mid]
        right_array = arr[mid:]

        merge_sort(left_array)
        merge_sort(right_array)

        i = j = k = 0
        while i < len(left_array) and j < len(right_array):
            if left_array[i] < right_array[j]:
                arr[k] = right_array[j]
                i += 1
            else:
                arr[k] = right_array[j]
                j += 1
            k += 1
        while i < len(left_array):
            arr[k] = left_array[i]
            i += 1
            k += 1
        while j < len(right_array):
            arr[k] = right_array[j]
            j += 1
            k += 1

arr = [8,4,2,10]
merge_sort(arr)
print(arr)