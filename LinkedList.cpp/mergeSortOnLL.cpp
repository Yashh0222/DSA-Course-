#include<iostream>
#include<list>
#include<iterator>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
  
};

class List{
   public:
   Node* head;
   Node* tail;

   List(){
    head = NULL;
    tail = NULL;
   }

   void push_front(int val){
    Node* newNode = new Node(val);

    if(head == NULL){
        head = tail = newNode;
    }else{
        newNode->next = head;
        head = newNode;
    }
   }

   void pop_front(){
    if(head == NULL){
        return;
    }

    Node* temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
   }

   void push_back(int val){
    Node* newNode = new Node(val);
    if (head == NULL)
    {
        head =tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
}

 
};



Node* merge(Node* left, Node* right){
    List ans;
    Node* i = left;
    Node* j = right;

    while(i != NULL && j != NULL){
        if(i->data <= j->data){
            ans.push_back(i->data);
            i = i->next;
        }else{
            ans.push_back(j->data);
            j = j->next;
        }
    }

    while (i != NULL)
    {
        ans.push_back(i->data);
        i = i->next;
    }
    
    while (j != NULL)
    {
        ans.push_back(j->data);
        j = j->next;
    }

    return ans.head;
}
Node* splitAtmid(Node* head){
    Node* slow = head;
    Node* prev = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if(prev != NULL){
        prev->next = NULL; // this cuts connection at middle
    }
    
    return slow; // this returns mid Node called right head of LL
}
Node* mergeSort(Node* head){

    if(head == NULL || head->next == NULL ){
        return head;
    }
    Node* rightHead = splitAtmid(head); // finding middle for right LL head

    Node* left = mergeSort(head); // head of lefft LL
    Node* right = mergeSort(rightHead); // head of right LL

    return merge(left, right );
  
}

Node* reverse(Node* head){
   Node* prev = NULL;
   Node* curr = head;
   Node* next = NULL;

   while(curr != NULL){
    next = curr->next;
    curr->next = prev;

    prev = curr;
    curr = next;
   }
   return prev;
}
Node* ZigZagLL(Node* head){
    
    //find midddle elemnt to to find 2d LL for reversing and merging it
    Node* rightHead = splitAtmid(head);

    // reverse the 2nd LL using reverse fun 
    Node* rightNodeRev = reverse(rightHead);

    Node* left = head;
    Node* right = rightNodeRev;
    Node* tail = right;

    while(left != NULL && right != NULL){
        Node*  nextleft = left->next;
        Node*  nextright = right->next;

        left->next = right;
        right->next = nextleft;

        tail = right;

        left = nextleft;
        right = nextright;
    }
    
    if(right != NULL){
        tail->next = right;
    }

    return head;
}

void printList(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<< "NULL\n";
   }
int main(){ 
    List ll;

    ll.push_back(4);
    ll.push_back(3);
    ll.push_back(2);
    ll.push_back(1);

    printList(ll.head);

    ll.head = mergeSort(ll.head);
    printList(ll.head);

    ll.head = ZigZagLL(ll.head);
    printList(ll.head);
    return 0; 
}