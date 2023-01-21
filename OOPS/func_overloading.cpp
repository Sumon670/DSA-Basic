//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
class apnacollege{
    public:
        void func(){
            cout<<"I am a function without argument."<<endl;
        }
        void func (int x){
            cout<<"I am a function with int argument."<<endl;
        }
        void func (double x){
            cout<<"I am a function with double argument."<<endl;
        }
};
int main()
{   
    apnacollege obj;
    obj.func();
    obj.func(4);
    obj.func(5.3);
    return 0;
}