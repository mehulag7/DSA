class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        if(n==0) return;
        if(m==0) {
            nums1=nums2;
            return;
        }
        while(i<m){
            if(nums1[i]>nums2[j]){
                int temp=nums1[i];
                nums1[i]=nums2[j];
                nums2[j]=temp;
                i++;
                sort(nums2.begin(),nums2.end());
            }
            else{
                i++;
            }
           //cout<<i<<endl;
        }
        for(int k=m;k<n+m;k++){
           nums1[k]=nums2[j];
           j++;
        }
    }
};