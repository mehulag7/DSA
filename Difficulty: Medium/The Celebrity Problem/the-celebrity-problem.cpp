class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        int n=mat.size();
        int top=0,down=mat.size()-1;
        while(top<down){
            if(mat[top][down]){
                top++;
            }
            else if(mat[down][top]) down--;
            else{
                top++;
                down--;
            }
        }
        int k=0;
        for(int i=0;i<n;i++){
            if(i!=top) k+=mat[top][i];
        }
        if(k!=0) return -1;
        else{
                    for(int i=0;i<n;i++){
             k+=mat[i][top];
        }
        if(k==n) return top;
        else return -1;
        }
    }
};