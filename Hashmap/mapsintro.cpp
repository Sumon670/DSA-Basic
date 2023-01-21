//Writen by CodemanSumon
#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
int main()
{
    //creation
    unordered_map<string,int>m;
    //insertion-1
    pair<string,int>p = make_pair("babbar",3);
    m.insert(p);
    //insertion-2
    pair<string,int>pair2("love",2);
    m.insert(pair2);
    //insertion-3
    m["mera"]=1;
    m["mera"]=2;
    //searching
    cout<<m["mera"]<<endl;
    cout<<m.at("babbar")<<endl;
    // output error & 0
    //cout<<m.at("unknownkey")<<endl;
    //cout<<m["unknwonkey"]<<endl;
    //output 0 & 0
    //cout<<m["unknwonkey"]<<endl;
    //cout<<m.at("unknownkey")<<endl;

    //size
    cout<<m.size()<<endl;
    //to check presence
    cout<<m.count("bro")<<endl;
    //erase
    m.erase("love");
    cout<<m.size()<<endl;
    for (auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    //iterator
    unordered_map<string,int> :: iterator it = m.begin();
    while (it != m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    // in unordered map values and keys are printed in random order but we can use map to print in the actual order
    return 0;
}
