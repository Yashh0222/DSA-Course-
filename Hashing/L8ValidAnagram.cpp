#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

// to check if two strings charetor are = or not 
bool validAnagram(string s, string t){
    if (s.size() != t.size())
    {
        return false;
    }
    
    unordered_map<char, int> freq; //<char , char freq>  

    // adding string s to map 
    for (int i = 0; i < s.size() ; i++)
    {
        if (freq.count(s[i]))
        {
            freq[s[i]]++;
        }else{
            freq[s[i]] = 1;   
        }
        
    }

    for (int i = 0; i < t.size(); i++)
    {
        if(freq.count(t[i])){
            freq[t[i]]--;
            if (freq[t[i]] == 0)
            {
                freq.erase(t[i]);
            }            
        }else{
            return false;
        }
    }
    return freq.size() == 0;   
} 
int main(){ 
    string s = "tulip";
    string t = "lipid";

    cout<<validAnagram(s,t)<<endl;
    return 0; 
}