//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
class Process{
    public:
    int order;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};
static bool cmp (Process a, Process b){
    //return a.bt < b.bt;
    return ((a.at == b.at)?(a.bt < b.bt):(a.at<b.at));
}
void find (vector<Process>& pro, int size){
    sort(pro.begin(), pro.end(),cmp);
    int ct=0;
    double avg_tat = 0.0;
    double avg_wt = 0.0;
    for (int i = 0; i < size; i++) {
        if (pro[i].at<=ct){
            ct += pro[i].bt;
            pro[i].ct = ct;
            pro[i].tat = pro[i].ct - pro[i].at;
            pro[i].wt = pro[i].tat - pro[i].bt;
            avg_tat += pro[i].tat * 1.0;
            avg_wt += pro[i].wt * 1.0;
        }
        else{
            ct += pro[i].at;
            ct += pro[i].bt;
            pro[i].ct = ct;
            pro[i].tat = pro[i].ct - pro[i].at;
            pro[i].wt = pro[i].tat - pro[i].bt;
            avg_tat += pro[i].tat * 1.0;
            avg_wt += pro[i].wt * 1.0;
        }
    }
    //printing
    cout<<"Process"<<"\t\t"<<"AT"<<"\t"<<"BT"<<"\t"<<"CT"<<"\t"<<"TAT"<<"\t"<<"WT"<<endl;
    for (int i=0; i<size; i++){
        cout<<"P"<<pro[i].order<<"\t\t"<<pro[i].at<<"\t"<<pro[i].bt<<"\t"<<pro[i].ct<<"\t"<<pro[i].tat<<"\t"<<pro[i].wt;
        cout<<endl;
    }
    cout <<"Avg tat is: "<<(avg_tat/size)<<endl;
    cout <<"Avg wt is: "<<(avg_wt/size)<<endl;
}
int main()
{
    int n;
    cout <<"The number of processes: ";
    cin>>n;
    cout<<"Enter: ";
    vector<Process>pro(n);
    for (int i=0; i<n; i++){
        int o,a,b;
        cin >>o>>a>>b;
        pro[i].order = o;
        pro[i].at = a;
        pro[i].bt = b;
    }
    find(pro,n);
    return 0;
}