class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        if(k>n) return -1;
        //sort(arr.begin(),arr.end());
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        int ans=0;
        //cout<<low<<" "<<high<<endl;
        while(low<=high){
            int mid=(low+high)/2;
            int count=0;
            int sum=0;
            for(int i=0;i<n;i++){
                if(sum+arr[i]<=mid){
                    sum+=arr[i];
                }
                else{
                    sum=arr[i];
                    count++;
                }
            }
            if(sum) count++;
            //cout<<mid<<" "<<count<<endl;
            if(count<=k){
                
                high=mid-1;
                if(count==k) ans=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};