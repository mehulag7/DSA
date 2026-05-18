// User function Template for C++

class Solution {
  public:
    bool isPossible(int a, int b) {
        // code here
        if(a==b) return false;
        if(a>b) swap(a,b);
        if(a==1 && b==2) return true;
        if(a==1 && b==3) return false;
        if(a==2 && b==3) return true;
    }
};