//Writen by CodemanSumon
#include<bits/stdc++.h>
using namespace std;
class heap{
    public:
    int arr[100];
    int size ;
    heap(){
        arr[0]=-1;
        size=0;
    }//creating a constructor
    void insert (int val){ //O(logn) comparing each insertion val with the parent
        size=size+1;
        int index = size;
        arr[index]=val;
        while (index > 1){
            int parent = index/2;
            if (arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                parent = index;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for (int i=1; i<=size;i++){
            cout<<arr[i]<<" ";
        }

    }
    void deletefromheap (){ //O(log(n))
        if (size==0){
            cout<<"Nothing to delete"<<endl;
            return;
        }
        //put last element into first index
        arr[1]=arr[size];
        //move last element
        size--;
        //take root node to its right pos
        int i=1;
        while (i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;
            if (leftIndex<size && arr[i]<arr[leftIndex]){
                swap (arr[i],arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex<size && arr[i]<arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i=rightIndex;
            }
            else{
                return;
            }
        }
    }
};
void heapify (int arr[],int n,int i){  //o(log(N))
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;
    if (left <=n && arr[largest]<arr[left]){
        largest=left;
    }
    if (right<=n && arr[largest]<arr[right]){
        largest=right;
    }

    if (largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
    return;
}
void heapsort(int arr[],int n){
    int size=n;
    while (size>1){
        //step1:swap
        swap(arr[size],arr[1]);
        size--;
        //step2
        heapify(arr,size,1);
    }
}//O(nlog(n))
int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    cout<<endl;
    h.deletefromheap();
    h.print();
    cout<<endl;
    int arr[6] = {-1,54,53,55,52,50};
    int n=5;
    //heapcreation
    for (int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    cout<<"printing the array: ";
    for (int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    //heapsort 
    heapsort(arr,n);
    cout<<"printing the sorted array: ";
    for (int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    cout<<"Using priority queue: "<<endl;
    //maxheap
    priority_queue<int>pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    cout<<"element at top: "<<pq.top()<<endl;
    pq.pop();
    cout<<"elment at top: "<<pq.top()<<endl;
    cout<<"size: "<<pq.size()<<endl;
    if (pq.empty()){
        cout<<"pq is empty"<<endl;
    }
    else{
        cout<<"pq is not empty"<<endl;
    }
    //min heap
    priority_queue<int,vector<int>,greater<int>>minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(5);
    minheap.push(3);
    cout<<"element at top: "<<minheap.top()<<endl;
    minheap.pop();
    cout<<"elment at top: "<<minheap.top()<<endl;
    cout<<"size: "<<minheap.size()<<endl;
    if (minheap.empty()){
        cout<<"it is empty"<<endl;
    }
    else{
        cout<<"it is not empty"<<endl;
    }
    return 0;
}
void heapifyn (vector<int> &arr,int n,int i){  //o(log(N))
    int smallest = i;
    int left = 2*i+1;
    int right = 2*i + 2;
    if (left < n && arr[smallest]>arr[left]){
        smallest=left;
    }
    if (right<n && arr[smallest]>arr[right]){
        smallest=right;
    }

    if (smallest!=i){
        swap(arr[smallest],arr[i]);
        heapifyn(arr,n,smallest);
    }
    return;
}
vector<int> buildMinHeap(vector<int> &arr)
{
    // Write your code here
    int n = arr.size();
    for (int i=n/2-1;i>=0;i--){
        heapifyn(arr,n,i);
    }
    return arr;
} //O(N)