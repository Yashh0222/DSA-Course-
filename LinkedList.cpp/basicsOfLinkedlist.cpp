#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }

    ~Node(){
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
};

class List {
private:
    Node* head;
    Node* tail;

public:
    List() {
        head = nullptr;
        tail = nullptr;
    }

    ~List(){
         if(head != NULL){
            delete head;
            head = NULL; 
         }  
    }
    
    void push_front(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

   void push_back(int val){
    Node* newNode = new Node(val);

    if(head == NULL){
        head = tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
   }

   void printList(){
    Node* temp = head;
      
    while (temp != NULL)
    {
         cout<<temp->data<<"->";
         temp = temp->next;
    
    }
    
    cout<<endl;
   }

   void insertAt(int val, int pos){
    Node* newNode = new Node(val);

    Node* temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    
   }

   void pop_front(){
    if(head == NULL){
        cout<<"Linlked list is empty"<<endl;
        return;
    }
    Node* temp = head;
    
    head = head->next;
    temp->next = NULL;
    delete temp ;
   }
   
   void pop_back(){
    Node* temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = NULL; // temp is tail prev after the loop
    delete tail;
    tail = temp;
   }

   int searchItr(int key){
    Node* temp = head;
    int idx = 0;
    
    while (temp != NULL)
    {
        if (temp->data == key)
        {
           return idx;
        }
        
        temp = temp->next;
        idx++;
    }
    return -1;
   }

   int helper(Node* temp, int key){

    if(temp == NULL){
        return -1;
    }
    if(temp->data == key){
        return  0;
    }

    int idx = helper(temp->next, key);
    if(idx == -1){
        return -1;
    }

    return idx + 1;

   }
   int searchRec(int key){
    helper(head, key);
   }

   //Reverse of Linked List
   void reverse(){
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL)
    {
        Node* next = curr->next;
        curr->next = prev;

        // changing prev to curr && curr  to next
        prev = curr;
        curr = next;  
    }
    
    head = prev;
   }

   int getSize(){
    Node* temp = head;
    int sz = 0;

    while (temp != nullptr)
    {
        temp = temp->next;
        sz++;
    }
    return sz;
   }

   // Removing nth element from end of linked list 
   void removeNth(int n ){
    int size = getSize();
    Node* prev = head;

    for (int i = 1; i < (size - n); i++)
    {
        prev = prev->next;
    }
    
    Node* toDel = prev->next;
    cout<<"Element to delete is "<<toDel->data<<endl; 

    prev->next = prev->next->next;
    
   }
};

int main() {
    List myList;
    myList.push_front(10);
    myList.push_front(20);
    myList.push_front(30);
    //myList.display();
    myList.printList();
    myList.insertAt(25,2);
    myList.printList();

    //myList.pop_front();
    //myList.printList();
//
    //myList.pop_back();
    //myList.printList();

    cout<<myList.searchItr(20)<<endl;
    cout<<myList.searchRec(20)<<endl;

    myList.reverse();
    myList.printList();

    myList.removeNth(2);
    myList.printList();
    return 0;
}