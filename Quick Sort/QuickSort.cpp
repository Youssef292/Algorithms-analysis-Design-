#include <iostream>
using namespace std;


//PartitionFunction
//input arr, start, end
int PartitionFunction(int arr[], int start , int end){
    // select the last element as a Pivot
    int Pivot = arr[end];
    // make i = -1
    int i = start - 1;
    // loop:
    for (int j = start ; j < end ; j++){
        if(arr[j] < Pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // if arr[j] < pivot
    // increment i
    // swap arr[i], arr[j]
    swap(arr[i+1], arr[end]);
    // return the pivot to it's intial postion and
    // return pivot index
    return i+1;
}

//QucikSort
// int arr, start , end

void QuickSort(int arr[], int start, int end){
    // if start < end
    if (start < end){
        // partition subarray PartitionFunction(int arr[], start, end)
        int PivotIndex = PartitionFunction(arr, start , end);
        // call QuickSort for the left subarray
        QuickSort(arr,start, PivotIndex -1);
        // call the QucikSort for the RightSunarray
        QuickSort(arr, PivotIndex+1, end);
    }

}





int main(){

    int arr[] = {4,3,1,2,5,9,7,10,6};
    int len =  sizeof(arr) / sizeof(arr[0]);

    for(int i = 0 ; i < len ; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
    QuickSort(arr, 0 , len - 1);

    for(int i = 0 ; i < len ; i++){
        cout << arr[i] << " ";
    }

}




