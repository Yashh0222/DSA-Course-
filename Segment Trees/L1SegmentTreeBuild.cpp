#include<iostream>
#include<vector>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

    void buildTree(vector<int>&arr, int start, int end, int node){
       // base case 
        if(start == end){
            tree[node] = arr[start];
            return ;
        }
        int mid = start + (end - start)/2;

        buildTree(arr, start, mid, 2*node+1); // to form left subtreee
        buildTree(arr, mid + 1, end, 2*node+2); // to form right sub tree

        tree[node] = tree[2*node+1] + tree[2*node+2]; // calculate every sum of twwo recursive step 
    }
    
    int rangeSum(int qi, int qj, int si, int sj, int node){
        
        // condition: givem range doent exxist at that node 
        if(qj < si || qi > sj){ // our range doent overlap
            return 0;
        }

        if(qi <= si && qj >= sj ){ // our range overlap completely 
            return tree[node];
        }

        // partial ovrlap 
        int mid = si + (sj - si)/2;
        
        return rangeSum(qi, qj, si, mid, 2*node+1)
                  + rangeSum(qi, qj, mid+1, sj, 2*node+2);

    }
    public:
    SegmentTree(vector<int> &arr){
         n = arr.size();
        tree.resize(4*n); // we have to resize it to store values
        buildTree(arr, 0, n-1, 0);   
    }

    
    void printTree(){
        for (int i = 0; i < tree.size(); i++)
        {
            cout<<tree[i]<<" ";
        }
        cout<<endl;
    }    

    int rangeQuery(int qi, int qj){
        return rangeSum(qi,qj, 0, n-1,0);
    }
};
int main(){ 
    vector<int> arr = {1,2,3,4,5,6,7,8};

    SegmentTree st(arr);
    cout<<st.rangeQuery(2,5)<<endl; //18
    cout<<st.rangeQuery(0,3)<<endl; //10 
    cout<<st.rangeQuery(6,7)<<endl; //15
    return 0; 
}