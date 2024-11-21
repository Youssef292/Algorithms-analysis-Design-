# MergeSort
# input arr , start , end
def MergeSort(arr, start, end):
    # exit if end >= start
    if end <= start:
        return
    #calc midpoint
    midpoint = (end + start) // 2


    #call MergeSort Twice
    MergeSort(arr, start , midpoint)
    MergeSort(arr, midpoint+1, end)


    # Call MergeFunction
    MergeFunction(arr, start, midpoint, end)





# MegreFunction
# input arr, start, midpoint, end
def MergeFunction(arr, start, midpoint, end):
     # i --> left_arr , j --> rigth_arr, k --> original array 
    
    #create two arrays
     left_length = midpoint - start+1
     right_length = end - midpoint

     left_arr = [0] * left_length
     right_arr = [0] * right_length
    
     for i in range(left_length):
         left_arr[i] = arr[start + i]
     for j in range(right_length):
         right_arr[j] = arr[midpoint + 1 +  j]   
     #compare and sort
     i = 0
     j = 0
     k = start
     while i < left_length and j < right_length:
         if left_arr[i] <= right_arr[j]:
             arr[k] = left_arr[i]
             i +=1 
         else:
            arr[k] = right_arr[j]
            j += 1
         k +=1

         # fill remain of the array 

     while i < left_length:
        arr[k] = left_arr[i]
        i+=1
        k+=1
     while j < right_length:
        arr[k] = right_arr[j]
        j+=1
        k+=1





array = [8,6,60,9,7,3,5,44]

print(array)

MergeSort(array, 0 , len(array)-1)

print(array)
     
