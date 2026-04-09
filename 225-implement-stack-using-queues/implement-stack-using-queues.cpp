class MyStack {
public:
    queue<int> q;
    int sz;

    MyStack() {
        sz = 0;
    }
    
    void push(int x) {
        q.push(x);

        for(int i = 0; i < sz; i++){
            q.push(q.front());
            q.pop();
        }

        sz++;
    }
    
    int pop() {
        int p = q.front();
        q.pop();
        sz--;
        return p;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return sz == 0;
    }
};