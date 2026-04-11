class StockSpanner {
public:
    stack<pair<int,int>> st;
    int p;
    StockSpanner() {
         p=0;
    }
    
    int next(int price) {
        p++;
        while(!st.empty() && st.top().first<=price) st.pop();
        int ans= st.empty()? p:p-st.top().second;
        st.push({price,p});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */