#include<iostream>
#include<string>
#include<vector>
using namespace std;
// SOrting of strings using merge sort

void merge(string str[], int st, int end, int mid){
    //int m = mid;
    //int n = end;
    vector<string> temp;
    int i = st;
    int j = mid + 1;

    while(i <= mid && j <= end){
        if(str[i] < str[j]){
            temp.push_back(str[i++]);
        }else{
            temp.push_back(str[j++]);
        }
    }

    while(i <= mid){
        temp.push_back(str[i++]);
    }

    while(j <= end){
        temp.push_back(str[j++]);
    }

    //copy to original str
    for(int idx = st,x = 0; idx <= end; idx++){
        str[idx] = temp[x++];
    }
}
void mergeSort(string str[], int st, int end){
    if(st >= end){
        return ;
    }

    //divide
    int mid = st + (end - st)/2;

    //For left part
    mergeSort(str, st, mid);

    //For right part
    mergeSort(str, mid + 1, end);

    // divided every string has to arrenge in sorted order so use merge
    merge(str, st, end, mid);

}

void print(string str[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<str[i]<<" ";
    }cout<<endl;
    
}
int main(){ 
    
    string str[4] = {"sun", "earth", "mars", "mercury"};
    int n = 4;
    mergeSort(str, 0, 3);
    print(str,4);
    return 0; 
}