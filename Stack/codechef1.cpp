#include <bits/stdc++.h>
#include <stack>
using namespace std;
int main() {
	// your code goes here
	int t; cin>>t;
	while (t--){
	    int n; 
        cin>>n;
	    stack <int> st;
        for (int i=1; i<=n; i++){
            st.push(i);
        }
        while (st.size() != 1){
            cout<<st.top()<<" ";
            st.pop();
            int x = st.top();
            st.pop();
            st.push(x);
        }
	}
	return 0;
}
