#include <vector>
using namespace std;

class MinStack {
    vector<int> data, mins;
public:
    MinStack() {
    }
    
    void push(int value) {
        int min_val = mins.empty() ? value : min(value, mins.back());
        data.push_back(value);
        mins.push_back(min_val);
    }
    
    void pop() {
        data.pop_back();
        mins.pop_back();
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return mins.back();
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