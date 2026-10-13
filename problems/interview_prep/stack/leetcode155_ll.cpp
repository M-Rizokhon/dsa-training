class MinStack {
private:
    struct Node {
        int val;
        int min;
        Node* next;

        Node(int v, int m) : val(v), min(m), next(nullptr) {}
    };

    Node* head;


public:
    MinStack() {
        head = nullptr;
    }
    
    void push(int value) {
        if (head == nullptr) {
            head = new Node(value, value);
        } else {
            int curr_min = head->min;
            Node* new_node = new Node(value, curr_min < value ? curr_min : value);
            new_node->next = head;
            head = new_node;
        }
    }
    
    void pop() {
        if (head != nullptr) {
            Node* old_head = head;
            head = old_head->next;
            delete old_head;
        }
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->min;
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