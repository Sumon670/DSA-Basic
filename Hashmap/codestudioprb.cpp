int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int,int>count;
    int maxfreq=0;
    int maxans=0;
    for (int i=0; i<arr.size(); i++){
        count[arr[i]]++;
        maxfreq = max(maxfreq,count[arr[i]]);
    }
    for (int i=0; i<arr.size(); i++){
        if (maxfreq == count[arr[i]]){
            maxans = arr[i];
            break;
        }
    }
    return maxans;
    //int maxi = INT_MIN;
    //int ans = -1;
    //for (auto i:count){
    //    if (i.second > maxi){
      //      maxi = i.second;
        //    ans = i.first; 
        //}
    //}
    //return ans;
    
}