#include <bits/stdc++.h>
using namespace std;
std::vector<int> v;
int frequency(int arr[], int size){
   bool check[size];
   for(int i=0;i<size;i++){
      check[i] = 0;
   }
   for(int i=0; i<size; i++){
      if(check[i]== 1){
         continue;
      }
      int count = 1;
      for(int j = i+1; j<size; j++){
         if (arr[i] == arr[j]){
            check[j] = 1;
            count++;
         }
      }
      v.push_back(count);
   }
}
int main(){
    int arr[] = {1, 2, 2, 1, 2, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    frequency(arr, size);
    sort(v.begin(),v.end());
    int d = v.back();
    if (d%2 ==0){
        v.back() = d/2;
    }
    else{
        v.back() = (d+1)/2;
    }
    sort(v.begin(),v.end());
    cout<<v.back()<<endl;
    return 0;
}