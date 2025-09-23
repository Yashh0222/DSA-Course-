#include<iostream>
using namespace std;

class Node{
   public:
   int data;
   Node* next;

   Node(int d){
    this-> data = d;
    this-> next = NULL;
   }
    //Destructor 
    ~Node(){
        int value = this->data;
        // memory free 
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout<<"memory is free for node data "<< value<<endl; 
   }
};

void insertNode(Node* &tail,int element,int d){
    //Empty list 
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }else{
        //For Non Empty list
        //Assuming that element is present
        Node* curr = tail;
        //Finding element after which new node has to be added
        while (curr->data != element)
        {
           curr = curr->next;
        }
         
        //Element is found crette node and point it 
        Node* temp = new Node(d);
        temp -> next = curr ->next ;
        curr -> next = temp;

    }
}

void print(Node* &tail){
    Node* temp = tail;

    if (tail == NULL)
    {
        cout<<" List is Empty"<<endl;
        return;
    }
    
    do
    {
        cout<<tail->data<<" ";
        tail = tail->next;

    } while (tail != temp);
    cout<<endl;
    
}
void deleteNode(Node* &tail , int value){
    // For Empty List 
    if(tail == NULL){
        cout<<"List is Empty"<<endl;
        return ;
    }else{
        //For Non Empty list 
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }
        // Pointing towards next Node of which node has to be deleted 

        prev->next = curr->next;
        // 1 Node linked list
        if (curr == prev)
        {
            tail = NULL;
        }
        
        // >2 Node linked list
        if (tail == curr)
        {
            tail = prev;
        }        
        curr->next = NULL;
        delete curr; 
    }
    
}

bool isCircularList(Node* head){
    //Base case
    if(head == NULL){
        return false;
    }

    //Crrete node to check if there is any null ptr
    Node* temp = head -> next;
    while(temp != NULL && temp != head){
        temp = temp -> next;
    }

    if(temp == head){
        return true;
    }else{
        return false;
    }
}
int main(){ 
    
    Node* tail = NULL;

    insertNode(tail,4,5);
    print(tail);
    //insertNode(tail,5,3);
    //print(tail);
    //insertNode(tail,3,2);
    //print(tail);
    //insertNode(tail,2,4);
    //print(tail);
    //insertNode(tail,4,8);
    //print(tail);

    //deleteNode(tail,5);
    //print(tail);
    if(isCircularList(tail)){
        cout<<"Linked list is circular "<<endl;
    }else{
        cout<<"list not circular"<<endl;
    }
    return 0; 
}