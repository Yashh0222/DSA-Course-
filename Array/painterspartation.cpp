#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int>arr , int n , int m, int mid){
	int painterpartation = 1;
	int time = 0 ; 

	for(int i = 0; i<n ; i++){
		if(time + arr[i] <= mid){
		    time = time  + arr[i];
		}else{
			painterpartation++;
			if(painterpartation > m || arr[i] > mid){
				return false;
			}
			time= arr[i];
		}
	} 
	return true;
}

int painterpartation(vector<int> arr , int n , int m){
	 int s = 0 ;
	 int sum= 0;
	 for(int i = 0; i<n ; i++){
		 sum = sum + arr[i];
	 }
	 int e = sum;
	 int ans = -1;
	 int mid = s +(e-s)/2;
	 while(s<=e){
		 if(isPossible(arr,n ,m,mid)){
			 ans = mid;
			 e = mid -1;
		 }else{
			 s = mid + 1;
		 }
		 mid = s +(e-s)/2;
	 }
	 return ans;
}
int main(){
    vector<int> arr= {5,5,5,5};
    //int n = 4 ,m = 2 ;

   cout << painterpartation(arr , 4 , 2)<<endl;;
    return 0;
}