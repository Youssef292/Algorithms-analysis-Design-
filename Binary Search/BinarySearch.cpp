#include <iostream>
using namespace std;
  
// Using Recursion


// input arr[] , len , key
int Binary_Search(int arr[], int low , int high, int key){
    // calc. Mid (low+high)/2
    if (low > high) {
        return -1;
    }

    int mid = (low + high) / 2;
    // if key == x[mid] --> return mid (Base Case)
    if(key == arr[mid]){

        return mid;

    }
    else if (key > arr[mid]){// if key > x[mid] --> move low after mid
         return  Binary_Search(arr,mid +1, high, key);

    }else if (key < arr[mid]){
        // else key < x[mid] --> move high before mid
         return Binary_Search(arr,low, mid-1, key);
    }

    // repeat until key == x[mid]
}



int main(){

    int arr[] = {4,5,6,7,8};

    int len =  sizeof(arr) / sizeof(arr[0]);



    int res = Binary_Search(arr,0,len-1,7);

   if (res != -1) {
       cout << res << endl;
   }else {
       cout << "No such element" << endl;
   }

}


// Complexity : O(log n)