#include <iostream>
using namespace std;


//MergeFunction
// read arr
// input len, start,midpoint,end
void MergeFunction(int arr[], int start, int midpoint, int end){
    // create 2 arrays left_array, right_array
    int left_len = midpoint - start +1;
    int right_len = end - midpoint;

    int left_arr[left_len] = {0};
    int right_arr[right_len] = {0};

    for(int i = 0 ; i < left_len ; i++){
        left_arr[i] = arr[start + i];

    }

    for(int j = 0 ; j < right_len ; j++){
        right_arr[j] = arr[midpoint + 1 + j];
    }

    // compare and sort [i for left_arr, j for right_arr, k for original arr]
    int i = 0 , j = 0;
    int k = start;
    while(i < left_len && j < right_len){
        if (left_arr[i] <= right_arr[j] ){
            arr[k] = left_arr[i];
            i++;
        }else{
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    // move remain items
    while (i < left_len)
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    while(j < right_len)
    {
        arr[k] = right_arr[j];
        j++;
        k++;
    }



}


//MergeSort
// read arr
// input len, start,end
void MergeSort(int arr[], int start, int end){
    //exit if end <= start
    if (end <= start){
        return;
    }else{
         // calc midpoint = (start + end)/2
         int midpoint  = (start + end)/2;
        // divde into 2new arrays
        // call MergeSort(leftarray) , MergeSort(Rightarray)
        MergeSort(arr,start,midpoint);
        MergeSort(arr,midpoint+1, end);
        // MergeFunction()
        MergeFunction(arr,start,midpoint,end);

    }

}

int main(){
    int arr[] = {8,6,60,9,7,3,5,44};
    int len =  sizeof(arr) / sizeof(arr[0]);
    for(int i = 0 ; i < len  ; i++){
        cout << arr[i] << " ";
    }
    cout <<"\n";

    MergeSort(arr,0,len-1);


     for(int i = 0 ; i < len  ; i++){
        cout << arr[i] << " ";
    }


}
