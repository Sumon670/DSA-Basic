//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
void subseq (string s, string ans){
    if (s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    string ros = s.substr(1);
    subseq (ros,ans);
    subseq (ros,ans+ch);
     
}
void subseq2(string s, string ans){
    if (s.length()==0){
        cout<<ans<<endl;
        return;
    }
    char ch = s[0];
    int code = ch;
    string ros = s.substr(1);
    subseq2(ros,ans);
    subseq2(ros,ans+ch);
    subseq2(ros,ans+to_string(code));
}
int main()
{
    //subseq("ABC","");
    //cout<<endl;
    subseq2 ("AB","");
    cout<<endl;
    return 0;
}