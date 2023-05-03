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
void find (vector<Process>& pro, int size){
    int ct=0,complete=0,t=0,x=INT_MAX,shortest=0;
    bool check = false;
    double avg_tat = 0.0;
    double avg_wt = 0.0;
    int rt[size];
    for (int i=0; i<size; i++){
        rt[i]=pro[i].bt;
    }
    while (complete != size){
        for (int i=0; i<size; i++){
            if ((pro[i].at <= t) && (rt[i]<x) && rt[i]>0 ){
                x = rt[i];
                check = true;
                shortest = i;
            }
        }
        if (check == false){
            t++;
            continue;
        }
        rt[shortest]--;
        x=rt[shortest];
        if(x==0){
            x=INT_MAX;
        }
        if(rt[shortest]==0){
            complete++;
            check=false;
            ct = t+1;
            pro[shortest].wt = ct - pro[shortest].bt - pro[shortest].at;
            if (pro[shortest].wt<0){
                pro[shortest].wt = 0;
            }
            pro[shortest].ct = ct;
            pro[shortest].tat = pro[shortest].ct - pro[shortest].at;
            avg_tat += pro[shortest].tat * 1.0;
            avg_wt += pro[shortest].wt * 1.0;
        }
        t++;
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