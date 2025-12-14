#include <bits/stdc++.h>
using namespace std;


//Mergesort Algorithm....

// Segregate Function Def.
void Segregate(vector<int> &v, int start, int end);
void Mergesort(vector<int> &v,int start, int Midpoint,int end);
int main(){

   vector<int> v = {9,5,1,4};
   for(int i : v) cout << i << " ";
   cout << "\n";
   Segregate(v,0,v.size()-1);
   for(int i : v) cout << i << " ";
}

//Segregate function Decl.

//Read the array (v) ,start , end
void Segregate(vector<int> &v, int start, int end){
    // if end >= start break
    if(end <= start) return;
    // calc. the midpoint 
    int Midpoint = (start + end) /2;
    Segregate(v,start,Midpoint);
    Segregate(v,Midpoint+1 , end);


    Mergesort(v,start,Midpoint,end);

}
// Read Vector (v) , start , midpoint, end 
void Mergesort(vector<int> &v, int start,int Midpoint,int end){
    //Create two new arrays left_portion, right_portion
    int Leftportion_size = Midpoint - start +1;
    int Rightportion_size = end - Midpoint;

    int Leftportion[Leftportion_size];
    int Rightportion[Rightportion_size];

    int i , j;
    i = j = 0;
    int k = start;


    //Fill the arrays

    for(int i = 0 ; i  < Leftportion_size ; i++){
        Leftportion[i] = v[start + i];
    

    }

     for(int j = 0 ; j  < Rightportion_size ; j++){
        Rightportion[j] = v[Midpoint + 1 + j];
        
    }

    while( i < Leftportion_size && j < Rightportion_size){
        if(Leftportion[i] <= Rightportion[j]){
            v[k] = Leftportion[i];
            i++;
        }else{
            v[k] = Rightportion[j];
            j++;
        }
        k++;

    }

    while(i < Leftportion_size){
        v[k] = Leftportion[i];
        i++;
        k++;
    }

      while(j < Rightportion_size){
        v[k] = Rightportion[j];
        j++;
        k++;
    }





}