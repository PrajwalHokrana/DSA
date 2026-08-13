class MinStack {
public:
    MinStack() {}

    stack<pair<int, int>> s;
    void push(int value) {
        if (s.empty()) {
            s.push({value, value});
        } else {
            int minimum=min(value , s.top().second);
            s.push({value,minimum});
        }
    }

    void pop() {
        s.pop();
    }

    int top() {
        return s.top().first;
    }

    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */