#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Node
{
public:
    unordered_map<char, Node*> children; // holds addres of every children in the form of node
    int endOfWord;

    Node()
    {
        endOfWord = false;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node;
    }

    void insert(string key)
    {
        Node *temp = root;

        for (int i = 0; i < key.size(); i++)
        {
            if (temp->children.count(key[i]) == 0)
            {
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true;
    }

    // Funtn to search word in trie
    bool search(string key)
    {
        Node *temp = root;

        for (int i = 0; i < key.size(); i++)
        {
            if (temp->children.count(key[i]))
            {
                temp = temp->children[key[i]];
            }
            else
            {
                return false;
            }
        }
        return temp->endOfWord; // if endofword is true it return true if it is false it return false
    }

    void helper(Node* root, string &ans, string temp){
        for(pair<char, Node*> child : root->children){
           if(child.second->endOfWord){ // if true then go upto end and find every prefix of and return ans
             temp += child.first;

            if((temp.size() == ans.size() && temp < ans) || temp.size() > ans.size()){
                ans = temp;
            }

            helper(child.second, ans, temp);
            temp = temp.substr(0, temp.size()-1); // backtraking 
           }
        }
    }

    string longestStringWithEOW()
    {
        string ans = "";
        helper(root, ans, ""); // "" = temp
        return ans;
    }
};

string longestString(vector<string> dict)
{
    Trie trie;

    for (int i = 0; i < dict.size(); i++)
    {
        trie.insert(dict[i]);
    }

    return trie.longestStringWithEOW();
}
int main()
{
    vector<string> dict = {"a", "banana", "app", "appl", "ap", "apple","apply"};
    
    cout<<longestString(dict)<<endl;

    return 0;
}