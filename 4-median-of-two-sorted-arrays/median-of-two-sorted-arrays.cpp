class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(n>m){
           return findMedianSortedArrays(nums2,nums1);
        }
        int low=0,high=n;
       
        int a=(n+m+1)/2;
        double ans;
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
                 if((n+m)%2==0){
                    ans=(double(max(l1,l2))+double(min(r1,r2)))/2.0;
                 }
                 else{
                    ans=double(max(l1,l2))/1.0;
                 }
                 break;
            }
        }
        return ans;
    }
};