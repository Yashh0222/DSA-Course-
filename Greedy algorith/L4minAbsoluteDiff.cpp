#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){ 
    //to find minm absoulte diff b/w 2 array
    vector<int> A = {4,1,8,7};
    vector<int> B = {2,3,6,5};

    // to get min absollute diff first sort both arrays 
    //so we can compare same index of both and get min absolute diff
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int absDiff = 0;
    for (int i = 0; i < A.size(); i++)
    {
        absDiff += abs(A[i] - B[i]);// abs is inbuilt fun to find absoulte
    }
    
    cout<<"Absoulte diff : "<<absDiff<<endl;
    return 0; 
}