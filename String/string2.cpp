//Writen by CodemanSumon
#include<bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str = "abcdefghijkl";
    for (int i=0; i<str.size(); i++){
        if (str[i]>='a' && str[i]<= 'z')
            str[i] -= 32;          //for convert to uppercase
    }

    string arr = "ABCDEFGHIJK";
    for (int i=0; i<arr.size(); i++){
        if  (arr[i]>='A' && arr[i]<= 'Z')
            arr[i] += 32;
    }
    cout<<arr<<endl;
    cout<<str<<endl;
    return 0;
}