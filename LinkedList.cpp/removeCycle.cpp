#include<iostream>
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

   void printList(){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<NULL<<endl;
   }
  
};

 void printList(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<< "NULL\n";
   }

   //Finding cycle and removing cycle
   void removeCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;  
        fast = fast->next->next;  

        if(slow == fast){
            cout<<"cycle is present"<<endl;
            isCycle = true;
            break;
        }
    }
      if(!isCycle){
         cout<<"cycle is not present"<<endl;
         return;
      }

      // this step is after finding the cycle mark slow to head and perforem 
      slow = head;
      
      // # exception case
      if(slow == fast){
        while (fast->next != slow)
        {
            fast = fast->next;
        }
        // remove cycle by fast->next
        fast->next = NULL; // cycle removed
        
    }else{
        Node* prev = fast;
        while (slow != fast)
        {
           slow = slow->next;
           prev = fast;
           fast = fast->next;
        }
        
        prev->next = NULL; //cyccle removed
        
    }

   
}

int main(){ 
    List ll;

    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.printList();

    // to find cycle and remove cycle
    ll.tail->next = ll.head;
    removeCycle(ll.head);
    printList(ll.head);
    return 0; 
}