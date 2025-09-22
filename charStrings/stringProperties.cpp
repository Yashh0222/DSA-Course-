#include<iostream>
#include<cstring>
using namespace std;
int main(){ 
    char str1[100] = "xyz";
    char str2[100] = "xyz";
    //str1 = "yash";// cant do this 
    // we use strcpy to copy string
    //strcpy(str1,"yash");//this copy yash to str1
    // to copy one string to other same proceess(destination , source)
    //strcpy(str1,str2);

    //strcat(str1,str2);//this concates two strings
    //cout<<str1<<endl;
    //cout<<str2<<endl;

    //string comparison 
    cout<<strcmp(str1,str2)<<endl;


    return 0; 
}