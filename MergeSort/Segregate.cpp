#include <iostream>
using namespace std;

void MergeFunction(int arr[], int start, int MidPoint, int end){

    int i , j , k;
    int LeftArr_len = MidPoint - start +1;
    int RightArr_len = end - MidPoint;

    int LeftArr[LeftArr_len] = {0};
    int RightArr[RightArr_len] = {0};


    for(i = 0 ; i < LeftArr_len; i++){
        LeftArr[i] = arr[start + i];
    }

    for(j = 0 ; j < RightArr_len; j++){
        RightArr[j] = arr[MidPoint+1+j];
    }

    i = 0;
    j = 0;
    k = start;

    while(i < LeftArr_len && LeftArr[i] <= 0){
        arr[k] = LeftArr[i];
        i++;
        k++;
    }

    while(j < RightArr_len && RightArr[j] <= 0){
        arr[k] = RightArr[j];
        j++;
        k++;
    }

    while (i < LeftArr_len )
    {
        arr[k] = LeftArr[i];
        i++;
        k++;
    }

    while (j < RightArr_len )
    {
        arr[k] = RightArr[j];
        j++;
        k++;
    }



}



void Segregate(int arr[], int start, int end){
    if(end <= start){
        return;
    }

    int MidPoint = (start+ end)/2;

    Segregate(arr,start,MidPoint);
    Segregate(arr,MidPoint+1,end);

    //Call The MergeFunction
    MergeFunction(arr,start,MidPoint,end);
}





int main(){
    int arr[] = {6,-5,12,10,-9,-1};
    int len =  sizeof(arr) / sizeof(arr[0]);
    for(int i = 0 ; i < len  ; i++){
        cout << arr[i] << " ";
    }
    cout <<"\n";

    //Segregate Function
    Segregate(arr,0,len -1);

    for(int i = 0 ; i < len  ; i++){
        cout << arr[i] << " ";
    }


}
