#include <bits/stdc++.h>
using namespace std;

int BinarySearch(vector<int> &arr, int start, int end, int key);


int main()
{
     vector<int> v = {1,2,3,4,5};
     int data = BinarySearch(v,0,v.size()-1,10);

     if (data != -1) {cout << "Value exsits";}
     else {cout << "Missing Value";}

    return 0;
}

int BinarySearch(vector<int> &arr, int start, int end, int key)
{
    int Temp = -1;
    // loop untill start <= end
    while(start <= end)
    {   
        
        // calc.Midvalue = (end - start) /2
        int Midvalue = (end + start) / 2;

        // Search for the key
        /**     [1,2,3,4,5,6]  key = 4 --> mid = (0+5) /2 = 2 , Midvalue = 3
         * idx  0 1 2 3 4 5
         *      | | |    |
         *      S k  M     E
         *  1 - key == arr[mid] --> return arr[mid];
         * 
         *  2 - key > arr[mid] --> move the start(low) after the mid --> start =  mid + 1; 
         * 
         *  3 - key < arr[mid] --> move the end(high) before the mid --> end = mid -1;
         * 
        */

        if (key == arr[Midvalue]) {
            Temp =  arr[Midvalue];  
            break;
        }
        else if (key > arr[Midvalue]) {
            start = Midvalue + 1;
        }
        else {
            end = Midvalue - 1;
        }
    }
    return Temp;
}