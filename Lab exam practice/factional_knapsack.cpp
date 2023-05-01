//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
class Item{
    public:
        int profit;
        int weight;
        Item (int p, int w){
            this->profit = p;
            this->weight = w;
        }
};
static bool cmp (pair<double,int> a, pair<double,int> b) {
    return a.first>b.first;
}
void solve (vector<Item>&items,int capacity) {
    vector<pair<double,int>>ans;
    for (int i=0; i<items.size(); i++) {
        double unit_val =  items[i].profit / items[i].weight;
        ans.push_back(make_pair(unit_val,items[i].weight));
    }
    sort(ans.begin(),ans.end(),cmp);
    double mx = 0;
    for (int i=0; i<ans.size(); i++) {
        if (ans[i].second > capacity){
            mx += capacity*ans[i].first;
            capacity = 0;
        }
        else{
            mx += ans[i].first*ans[i].second;
            capacity -= ans[i].second;
        }
    }
    cout<<"Maximum profit will be: "<<mx<<endl;
}
int main()
{
    vector<Item> items;
    Item item1(60,10);
    items.push_back(item1);
    Item item2(120,30);
    items.push_back(item2);
    Item item3(100,20);
    items.push_back(item3);
    int capacity = 50;
    solve (items,capacity);
    return 0;
}