#include <bits/stdc++.h>
using namespace std;


int MaxCrossingSum(vector<int> &arr, int start , int Midpoint , int end);
int MaxSubarrayDivideConquer(vector<int> &arr, int start , int end);
int main()  
{

    vector<int> v = {10};
    cout <<MaxSubarrayDivideConquer(v,0,v.size()-1)<< endl;


    return 0;
}


int MaxSubarrayDivideConquer(vector<int> &arr, int start , int end)
{
    // Base case : arr size == 1 --> start == end
    if (start == end) return arr[start]; // [end] --> the same index 

    // Clac.Midpoint (start + end ) /2
    int Midpoint = (start + end) /2;


    //Divide int Subarrays
    int LeftMax = MaxSubarrayDivideConquer(arr,start,Midpoint);
    int RightMax = MaxSubarrayDivideConquer(arr, Midpoint + 1 , end);
    int CrossMax = MaxCrossingSum(arr, start , Midpoint , end);


    return max(LeftMax,max(RightMax,CrossMax));

    


}

int MaxCrossingSum(vector<int> &arr, int start , int Midpoint , int end)
{   
    int LeftSum = 0;
    int MaxLeftSum = INT_MIN;

    for(int i = Midpoint; i >= start ; i--){
        LeftSum +=arr[i];
        if(LeftSum > MaxLeftSum){
            MaxLeftSum = LeftSum;
        }
    }

      int RightSum = 0;
      int MaxRightSum = INT_MIN;

     for(int j = end; j >= Midpoint+1 ; j--){
        RightSum +=arr[j];
        if(RightSum > MaxRightSum){
            MaxRightSum = RightSum;
        }
    }

    int CrossSum = MaxLeftSum + MaxRightSum;


    return CrossSum;
}