#include<iostream>
#include<queue>
using namespace std;
// to find first char which doesnt repeat and push it queue or push -1 

void firstNonRepeat(string str){
    queue<char> q;
    int freq[26] = {0};

    for (int i = 0; i < str.size(); i++)
    {
        char ch = str[i];
        q.push(ch);
        freq[ch - 'a']++;
        

        // check if freq is greater tham 1 then not our ans so pop until empty
        while (!q.empty() && freq[q.front()- 'a'] > 1)
        {
            q.pop();
        }
        
        if(q.empty()){
            cout<<"-1\n";
        }else{
            cout<<q.front()<<"\n";
        }

    }
    
}
int main(){ 
    string str = "aabccxb";
    
    firstNonRepeat(str);
    return 0; 
}