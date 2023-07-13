class MyStack {
    queue<int> q1;
    
public:
    MyStack() {
        
    }
    
    void push(int x) {
       q1.push(x);
       int sz = q1.size()-1;
        while(sz){
            q1.push(q1.front());
            q1.pop();
            sz--;
        }
    }
    
    int pop() {
       if(q1.empty())  return -1;
       int x = q1.front();
       q1.pop();
        return x;
    }
    
    int top() {
        return q1.empty()?-1:q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */