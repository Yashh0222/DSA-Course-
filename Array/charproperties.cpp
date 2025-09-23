#include<iostream>
#include<string>
#include<cctype>
using namespace std;

char tolowercase(char ch ){
  if (ch >= 'a' && ch<= 'b')
  {
    return ch;
  }else{
    char temp = ch - 'A' + 'a';
    return temp ;
  
  }
  
}
bool checkPalindrom(char a[] , int n){
  int s = 0;
  int e = n-1;

  while (s<=e)
  {
    //for nonalgebric value(symbol and white space)
     if(! isalnum(a[s]))
    {
      s++;
    }else if(! isalnum(a[e]))
    {
      e--;
    }
    else if ( a[s]  =!  a[e] )
    {
      return false;
    }else {
      s++;
      e--;
    }
    
  }
  return true;

}

void reverse(char name[], int n){
    int s = 0;
    int e = n-1;
    
    while (s<e)
    {
      swap(name[s++],name[e--]);
    }
    
}

int getLength(char name[]){
  int count =0;
  for (int  i = 0; name[i] != '\0'; i++)

  {
    count++;
  }
  return count;
  
}
int main(){ 
    
    char name[20];

    cout<<"enter ur name"<<endl;
    cin>>name;

    cout<<"ur name is ";
    cout<<name<<endl; 

    int len = getLength(name);
    cout<<"the length of name is "<<len<<endl; 

    reverse(name , len);
     cout<<"ur reversed name is ";

    cout<<name<<endl; 
    cout<<"palandrom or not "<<checkPalindrom(name ,len)<<endl; 

    cout<<"to lower case "<<tolowercase('b')<<endl; 
    cout<<"to lower case "<<tolowercase('B')<<endl; 
    
   
    return 0; 
}