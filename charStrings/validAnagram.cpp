#include<iostream>
using namespace std;
bool validAnagram(string str1, string str2){
    if(str1.length() != str2.length()){
        cout<<"Not valid anagram"<<endl;
        return false;
    }

    int count[26] = {0};// this makes array to add ccount
    for (int i = 0; i < str1.length(); i++)
    {
        count[str1[i] - 'a']++;//this finds which element it is and makes count ++
    }

    for (int i = 0; i < str2.length(); i++)
    {
        if (count[str2[i]-'a'] == 0)
        {
            cout<<"Not valid anagram"<<endl;
            return false;
        }
        
    }
    
    cout<<" valid anagram"<<endl;
        return true;

}
int main(){ 
    string str1 = "cat";
    string str2 = "dog";

    validAnagram(str1 ,str2);
    return 0; 
}