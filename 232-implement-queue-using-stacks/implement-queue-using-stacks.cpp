class MyQueue {
public:
    stack<int> s1,s2;
    int sz;
    MyQueue() {
        sz=0;
    }
    
    void push(int x) {
        s1.push(x);
        sz++;
    }
    
    int pop() {
        sz--;
        if(!s2.empty()){
            int q=s2.top();
            s2.pop();
            return q;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
         int q=s2.top();
            s2.pop();
            return q;
    }
    
    int peek() {
         if(!s2.empty()){
            int q=s2.top();
            return q;
        }
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
         int q=s2.top();
            return q;
    }
    
    bool empty() {
        return (sz==0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */