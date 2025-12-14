#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> x =[1,9,5,4];
    int key = 0;

    for(int i = 1 ; i < x.size(); i++){
        key = x[i];

        for(int j = i -1 ; j >= 0 ; j--){
           if(key > x[j]) x[j+1] = x[j];
           else break;
        }
        x[j+1] = key
    }



}



