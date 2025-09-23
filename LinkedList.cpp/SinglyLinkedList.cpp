#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //Constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    //Destructor 
    ~Node(){
        int value = this->data;
        // memory free 
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free for node data "<< value<<endl;

        
    }
};


void insertAtTail(Node* &tail , int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;

}
void insertAtHead(Node* &head , int d){
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;

}
void insertAtPosition(Node* &tail, Node* &head, int position, int d ){
    // Insert at starrt 
    if(position == 1){
        insertAtHead(head , d);
        return;
    }

    Node* temp = head;
    int cnt =1;

    while(cnt < position-1 && temp -> next != NULL){
        temp = temp -> next;
        cnt++;
    }

    // insert at tail 
    if(temp -> next == NULL){
        insertAtTail(tail,d);
        return ;
    }

    // Creating NOde to insert d
    Node* nodeToInsert = new Node(d);
    
    nodeToInsert ->next = temp -> next;
    temp -> next = nodeToInsert;
}

void deleteNode(int position , Node* &head, Node*  &tail){
    // deleting first Node 
    if(position == 1){
        Node* temp = head;
        head = head->next;
        //free Up the Memory
        temp -> next = NULL;
        delete temp;
    }else{
        // Deleting middle node 
        Node* curr = head;
        Node* prev = NULL;

        int cnt =1;
        while(cnt < position){
           prev = curr;
           curr = curr -> next;
           cnt++;
        }
        
        prev -> next = curr -> next;
        if(curr->next == NULL)
        {
         tail=prev;
        }
        //curr -> next = NULL;
        delete curr;
    }

    
}

void print(Node* &head){
    Node* temp = head;

    while (temp != NULL)
    {
        cout<< temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
    
}

/*bool detectLoop(Node* head){
    // Base condition 
    if(head == NULL){
        return false;
    }
    
    map<Node* , bool> visited;

    Node* temp = head;
    while(temp != NULL){
        // when element is visited twise contion means loop is present
        if(visited[temp] == true){
            cout<<"Element visited twise at "<<temp->data<<endl;
            return true;
        }
        // Marks every element true 
        visited[temp] = true;
        temp = temp -> next;

    }
  
    return false;
}*/

Node* floydDetectionLoop(Node* head){
    if (head == NULL)
    {
        return NULL;
    }

    Node* fast = head;
    Node* slow = head;

    while (slow != NULL && fast != NULL)
    {
        fast = fast -> next;
        if (fast -> next != NULL)
        {
           fast = fast  -> next;
        }

        slow = slow -> next;

        if(slow == fast){
            return slow;
        }
        
    }
    return NULL;
}

Node* getStartingNode(Node* head){

    if (head == NULL)
    {
        return NULL;
    }

    Node* intersection = floydDetectionLoop(head);
    Node* slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
    
}

void removeLoop(Node* head){
    if(head == NULL){
        return;
    }

    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    while(temp->next != startOfLoop){
        temp = temp->next;
    }
    temp -> next = NULL;

}
int main(){ 
    //creating a new node
    Node* node1 = new Node(10);
    //cout<< node1 -> data << endl;
    //cout<< node1 -> next << endl;

    // Pointing head to node 1
    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertAtTail(tail , 12);

    print(head);

    insertAtTail(tail , 15);
    print(head);

    insertAtTail(tail , 30);
    print(head);

    tail -> next = head ->next;
    
    // Detects the loop
    if(floydDetectionLoop(head)){
        cout<<"Loop is present"<<endl;
    }else{
        cout<<"Loop is absent"<<endl;
    }

    //this gets starting node list
    Node* loop = getStartingNode(head);
    cout<<"Loop stats at "<<loop->data<<endl;

    //this removes the loop 
    removeLoop(head);
    print(head);
    
    /*insertAtPosition(tail ,head,2,22);
    print(head);

    deleteNode(4 ,head,tail);
    print(head);
    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;*/
    return 0; 
}