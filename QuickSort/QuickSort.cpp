#include <bits/stdc++.h>
using namespace std;

void Quick_Sort(vector<int> &arr, int start , int end);

int main(){


    vector<int> v = {-5, 3, -1, 7, -9, 2};
    Quick_Sort(v,0,v.size()-1);
    for(auto i : v) cout << i << " ";

    return 0;
}

void Quick_Sort(vector<int> &arr, int start, int end){

    if (start >= end) return;

    int pivot = end;
    int ptr = start-1;
    for(int i = start ; i < end ; i++) // o(N)
    {
        if(arr[i] < arr[pivot])
        {
            swap(arr[ptr+1], arr[i]);
            ptr++;
        }
    }
    swap(arr[ptr+1],arr[pivot]);

   
  
    Quick_Sort(arr,start,ptr);
    Quick_Sort(arr,ptr+2,end);
    

}

