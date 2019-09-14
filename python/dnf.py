def swap (arr, i1, i2):
    tmp = arr[i1]
    arr[i1] = arr[i2]
    arr[i2] = tmp

def dnf(arr):
    """
    dutch national flag sorting algorithm. Given a list of 1,2,0
    sort the list
    1. create low and high pointers to ends of array
    2. create a mid pointer that starts at the beginning and
       goes over every element
    3. if the element at arr[mid] is a 2, then swap arr[mid] 
       and arr[high] and decrease the high pointer by 1.
    4. If the element at arr[mid] is a 0, then swap arr[mid]
       and arr[low] and increase the low and mid pointers by 1.
    5. If the element at arr[mid] is a 1, don't swap anything
       and just increase the mid pointer by 1.
    """
    low = 0
    high = len(arr) - 1
    mid = low
    while mid <= high:
        if arr[mid] == 2:
            swap(arr, mid, high)
            high -= 1
        elif arr[mid] == 0:
            swap(arr, mid, low)
            low += 1
            mid += 1
        else:
            mid += 1
    return arr

print(dnf([0,2,2,2,2,2,1]))
print(dnf([1,2,0,0,2,1,1]))
print(dnf([0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,1,1,1,1,1,1,1]))