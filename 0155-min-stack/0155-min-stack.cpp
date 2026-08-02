class MinStack {
public:
    MinStack() {}
    
    void push(int val) {
        if(st.empty()) {
            st.push(0);
            min = val;
        } else {
            st.push(val - min);
            if(val < min) min = val;
        }
    }
    
    void pop() {
        if(!st.empty()) {
            if(st.top() < 0) {
                min -= st.top();
            }
            st.pop();
        }
    }
    
    int top() {
        if(st.top() < 0) {
            return min;
        } else {
            return st.top() + min;
        }
    }
    
    int getMin() {
        return min;
    }

private:
    long min;
    stack<long> st;
};
