//Writen by CodemanSumon
#include<bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string s = "35280037031";
    sort (s.begin(), s.end(), greater<int>());
    cout<<s<<endl;
    return 0;
}