class Solution {
    public int maximumPopulation(int[][] logs) {
       int[] arr=new int[101];
       for(int i=0;i<101;i++) arr[i]=0;
       for(int i=0;i<logs.length;i++){
        arr[logs[i][0]-1950]++;
        arr[logs[i][1]-1950]--;
       }
       int mx=-1;
       int count=0;
       int ans=-1;
       for(int i=0;i<101;i++){
        count+=arr[i];
        if(count>mx){
          ans=i+1950;
          mx=count;
        }
       }
       return ans;
    }
}