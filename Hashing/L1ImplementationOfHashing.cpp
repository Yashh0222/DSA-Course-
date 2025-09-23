#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node
{
public:
    string key;
    int val;
    Node *next;

    Node(string key, int val)
    {
        this->key = key;
        this->val = val;
        next = NULL;
    }

    ~Node()
    {
        next = NULL;
    }
};

class hashTable
{
    int totSize;
    int currSize;
    Node **table;

    // Fixed hash function
    int hashFunction(string key)
    {
        int idx = 0;
        for (int i = 0; i < key.size(); i++)
        {
            idx = (idx + (key[i] * key[i]) % totSize) % totSize; //  Final % totSize added
        }
        return idx;
    }

    void rehash()
    {
        Node **oldtable = table; // to keep the track of old table
        int oldsize = totSize;

        totSize = 2 * totSize;
        table = new Node *[totSize];

        for (int i = 0; i < totSize; i++)
        {
            table[i] = NULL;
        }

        currSize = 0;

        for (int i = 0; i < oldsize; i++)
        {
            Node *temp = oldtable[i];
            while (temp != NULL)
            {
                insert(temp->key, temp->val);
                temp = temp->next;
            }
        }

        for (int i = 0; i < oldsize; i++)
        {
            Node *head = oldtable[i];
            while (head != NULL)
            {
                Node *nextNode = head->next;
                head->next = nullptr;
                delete head;
                head = nextNode;
            }
        }

        delete[] oldtable;
    }

public:
    hashTable(int size = 5)
    {
        totSize = size;
        currSize = 0;

        table = new Node *[totSize];

        for (int i = 0; i < totSize; i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string key, int val)
    {
        int idx = hashFunction(key);

        Node *newNode = new Node(key, val);

        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;

        double lambda = currSize / (double)totSize; /// this is used to find if table is full and need to rehashing
        if (lambda > 1)
        {
            rehash();
        }
    }

    void remove(string key)
    {
        int idx = hashFunction(key);

        Node *temp = table[idx];
        Node *prev = temp;

        while (temp != NULL)
        {
            if (temp->key == key)
            { // if node to be deleted is head node at table idx
                if (prev == temp)
                {
                    table[idx] = temp->next;
                }
                else
                { // if the node to be deleted is not head
                    prev->next = temp->next;
                }
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }
    bool exists(string key)
    {
        int idx = hashFunction(key);

        Node *temp = table[idx];
        while (temp != nullptr)
        {
            if (temp->key == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int search(string key)
    {
        int idx = hashFunction(key);

        Node *temp = table[idx];
        while (temp != nullptr)
        {
            if (temp->key == key)
            {
                return temp->val;
            }
            temp = temp->next;
        }
        return -1;
    }

    void print()
    {

        for (int i = 0; i < totSize; i++)
        {
            cout << "Idx" << i << "->";
            Node *temp = table[i];
            while (temp != NULL)
            {
                cout << "(" << temp->key << "," << temp->val << ") ->";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    hashTable ht;

    ht.insert("india", 150);
    ht.insert("china", 150);
    ht.insert("US", 50);
    ht.insert("Nepal", 10);
    ht.insert("UK", 20);

    if (ht.exists("india"))
    {
        cout << "India population : " << ht.search("india") << endl;
    }

    ht.print();
    cout<<"-----------"<<endl;

    ht.remove("china");
    ht.print();
    return 0;
}
