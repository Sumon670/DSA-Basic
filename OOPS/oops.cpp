//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
class student{
    string name;
    public:
    int age;
    bool gender;
    void printInfo(){
        cout<<"Name = ";
        cout<<name<<endl;
        cout<<"Age = ";
        cout<<age<<endl;
        cout<<"Gender = ";
        cout<<gender<<endl;
    }
    void getname (){
        cout<<name<<endl;
    }
    student (string s, int a, int g){
        cout<<"Parameterised Constructor"<<endl;
        name = s;
        age = a;
        gender = g;
    } //parametrised constructor 
    student (){
        cout<<"Default Constructor"<<endl;
    }//default constructor
    
    student (student &a){
        cout<<"Copy Constructor"<<endl;
        name = a.name;
        age = a.age;
        gender = a.gender;
    }
    ~student (){
        cout<<"Destructor called"<<endl;
    }
    bool operator == (student &a){
        if (name == a.name && age == a.age && gender == a.gender){
            return true;
        }
        return false;
    }
};
int main()
{
    //student a;
    //a.name = 'Urvi';
    //a.age = 20;
    //a.gender = 1;
    //student arr[3];
    //for (int i=0; i<3; i++){
    //    cout<<"Name = ";
    //    cin>>arr[i].name;
    //    cout<<"Age = ";
    //    cin>>arr[i].age;
    //    cin>>arr[i].gender;
    //    cout<<"Gender = ";
    //    cin>>arr[i].gender;
    //}
    //for (int i=0; i<3; i++){
    //    arr[i].printInfo();
    //}
    student a ("Urvi",20,1);
    //a.printInfo();
    student b;
    student c = a;
    if (c==a){
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Not same"<<endl;
    }
    return 0;
}