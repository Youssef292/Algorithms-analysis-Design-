# Normal Methoud

def BinarySearch(lst, key):
    low = 0
    high = len(lst) -1

    while low <= high:
        mid = (low + high) // 2
        if key == lst[mid]:
            return mid
        elif key > lst[mid]:
            low = mid +1
        else:
            high = mid -1
    return -1

Sorted_lst = [1,3,4,5,6,7,10]

print(BinarySearch(Sorted_lst,20))