class Solution {
  public:
    int kthElement(vector<int> &nums1, vector<int> &nums2, int k) {
        // code here
        int n=nums1.size();
        int m=nums2.size();
        if(n>m){
           return kthElement(nums2,nums1,k);
        }
        int low=max(0,k-m),high=min(k,n);
       
        int a=k;
        //int ans;
       //  if(n==0) return nums2[a-1];
        while(low<=high){
            int mid1=(low+high)/2;
            int mid2=a-mid1;
            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX,r2=INT_MAX;
            if(mid1<n) r1=nums1[mid1];
            if(mid2<m) r2=nums2[mid2];
            if(mid1-1>=0) l1=nums1[mid1-1];
            if(mid2-1>=0) l2=nums2[mid2-1];
            if(l1>r2){
                high=mid1-1;
            }
            else if(l2>r1){
                low=mid1+1;
            }
            else{
                    return max(l1,l2);
            }
        }
        return 0;
    }
};