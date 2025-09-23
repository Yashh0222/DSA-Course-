#include<iostream>
#include<vector>
using namespace std;

class Heap{
    vector<int> vec; // to add BT values (max heap)
    public:

    void push(int val){ // To push value in heap 
        //push directly bcz it gets add to ending level branch
        vec.push_back(val);
        
        // added value should be fixed at correct posn
        int x = vec.size()-1; // get that childIndex to swap it parentsIndex
        int parI = (x-1)/2; // (parI = parentIndex) (x = childIndex)
        
        while(parI >= 0 && vec[x] > vec[parI]){ // to make min heap change sign to <
            swap(vec[x], vec[parI]);
            x = parI; // to check until it gets to correct place 
            parI = (x-1)/2;
        }
    }

    void heapify(int i){ // i = parentIndex
        if(i >= vec.size()){
            return;
        }
        int left = 2*i+1;
        int right = 2*i+2;

        int maxIdx = i;
        if (left < vec.size() && vec[left] > vec[maxIdx])
        {
            maxIdx = left;
        }
        
        if (right < vec.size() && vec[right] > vec[maxIdx])
        {
            maxIdx = right;
        }
        
        swap(vec[i], vec[maxIdx]);// parentsIndex 
        if(maxIdx != i){ // for childIndex swapping
            heapify(maxIdx);
        }

    }
    void pop(){
        //step:1 swap first and last value
        swap(vec[0], vec[vec.size()-1]);

        //step:2 pop last idx value
        vec.pop_back();

        //step:3 heapify adjust the BT with max heap adding higher element up 
        heapify(0);
    }

    int top(){
        return vec[0]; // Top element is alwyas first in vec
    }

    bool isempty(){
        return vec.size() == 0;
    }
};
int main(){ 
    Heap heap;
    heap.push(50);
    heap.push(10);
    heap.push(100);

    cout<<"Top : "<<heap.top()<<endl;//100
    heap.pop();
    cout<<"Top : "<<heap.top()<<endl;//50
    return 0; 
}