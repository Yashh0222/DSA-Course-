// in this code at every range in tree there is maximum
#include<iostream>
#include<vector>
using namespace std;

class SegmentTree{
    vector<int> tree;
    int n ;

    void buildTree(vector<int> &nums, int start ,int end, int node){
        if (start == end)
        {
            tree [node] = nums[start];
            return;
        }

        int mid = start + (end - start)/2;

        buildTree(nums, start, mid, 2*node+1); // left subtreee
        buildTree(nums, mid+1, end, 2*node+2); // right subtree

        tree[node] = max(tree[2*node+1], tree[2*node+2]);
        
    }

    // this finds maximum b/w given range 
    int maxQuery(int qi, int qj, int si, int sj, int node){
        
        
        if(qj < si || qi > sj){ //no overlap means range is out from particluar node 
            return INT32_MIN;    
        }

        if(qi <= si && qj >= sj ){ // complete
            return tree[node];
        }

        // partial ovrlap 
        int mid = si + (sj - si)/2;
        
        int leftMax = maxQuery(qi, qj, si, mid, 2*node+1);
        int rightMax = maxQuery(qi, qj, mid+1, sj, 2*node+2);
                  
        return max(leftMax, rightMax);
    }

    // this funtn is for updating the value
    void updateHelper(int idx,int newVal, int start, int end,int node){
        // base case 
        if(start == end){
            tree[node] = newVal; // we reach the index val and replace it with given newval 
            return;
        }
        int mid = start + (end - start)/2;

        if (idx >= start && idx <= mid)
        {
            updateHelper(idx, newVal, start, mid, 2*node+1); // to go to left subtree
        }else{            
            updateHelper(idx, newVal, mid+1, end, 2*node+2);// for right subtree
        }
        
        tree[node] = max(tree[2*node+1] , tree[2*node+2]);

    }
    public:
    SegmentTree(vector<int> &nums){
         n = nums.size();
        tree.resize(4*n);
        buildTree(nums, 0, n-1, 0);
    }

    void printTree(){
        for(int el : tree){
            cout<<el<<" ";
        }
        cout<<endl;
    }

    int rangeMax(int qi, int qj){
        return maxQuery(qi,qj, 0, n-1,0);
    }

    void updateMax(int idx, int newVal){
        return updateHelper(idx,newVal, 0, n-1,0);
    }

};
int main(){ 
    vector<int> nums = {6,8,-1,2,17,1,3,2,4};

    SegmentTree st(nums);

    st.printTree();
    cout<<st.rangeMax(2,5)<<endl; //17
    st.updateMax(4,5);
    cout<<st.rangeMax(0,8)<<endl; //8
     
    return 0; 
}