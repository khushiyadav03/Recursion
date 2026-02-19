class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int size = q.size();
        while(size-- > 1){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(q.empty()){
            return -1;
        }

        int top = q.front();
        q.pop();
        return top;
    }
    
    int top() {
        if(q.empty()){
            return -1;
        }
        return q.front();
    }

    int size(){
        return q.size();
    }
    
    bool empty() {
        return q.empty();
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