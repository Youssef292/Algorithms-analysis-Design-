#include <bits/stdc++.h>
using namespace std;



void SegregateNumbers(int *arr, int start, int end);
void Merge(int *arr, int start, int midPoint, int end);
bool compare(int a, int b);

int main(){

    int arr[] ={6,-5,12,10,-9,-1};
    for(auto & ele : arr) cout << ele << " ";
    cout << "\n";
    SegregateNumbers(arr,0,5);
    for(auto & ele : arr) cout << ele << " ";



    return 0;
}


/**
 * Divide
 * 1 - Read array (x), Start, End
 * 2 - start >= end --> break
 * 3 - Calc. midpoint = (start + end) /2
 * 4 - Divide The Portion into two new arrays
 * 5 - Call the Divide Function twice for the left and right side
 * 6 - Merge the two portions
 *
 */

void SegregateNumbers(int *arr, int start, int end){
    if(start >= end) return;

    int midPoint = (start + end) /2;

    SegregateNumbers(arr, start , midPoint);
    SegregateNumbers(arr,midPoint+1, end);

    Merge(arr,start,midPoint,end);

}

/***
 * Merge
 * 1 - Read the array(x), start, midPoint, end
 * 2 - Create two new arrays for each side
 *      2.1 cala. the left and right side size
 *          2.1.1 leftSize = midPoint - start +1 ;
 *                rightSize = end - midpoint
 *          2.2  Create two new arrays with the new sizes
 *
 * 3 - Compare all the items in the arrays and sort them in original array (in-place) --> Two Pointers tech.
 *
 * 4 - Move the remain items in each array in the original one
 *
 */
void Merge(int *arr, int start, int midPoint, int end){
    int leftSize = midPoint - start +1;
    int rightSize = end - midPoint;

    int *leftArray = new int[leftSize];
    int *rightArray = new int[rightSize];

    for(int i = 0 ; i < leftSize ; i++){
        leftArray[i] = arr[start + i];
    }

    for(int j = 0 ; j < rightSize; j++){
        rightArray[j] = arr[j + midPoint +1];
    }

    int l , r , k;
    l = 0;
    r = 0;
    k = start;

    while (l < leftSize  && r < rightSize) {
        if (compare(leftArray[l], rightArray[r])) {
            arr[k++] = leftArray[l++];
        }else {
            arr[k++] = rightArray[r++];
        }
    }

    while (l < leftSize) {
        arr[k++] = leftArray[l++];
    }

    while (r < rightSize) {
        arr[k++] = rightArray[r++];
    }

}
bool compare(int a, int b) {
    if (a < 0 && b >=0) return true;
    if (a >= 0 && b < 0) return false;


    if (a < 0 && b < 0) return  a > b;

    return a < b;
}
// Time O(n log n) 
// Spcae O(n)