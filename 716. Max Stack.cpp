class MaxStack {
private:
    stack<int> maxST;
    stack<int> allST;
public:
    MaxStack() {
        
    } 
    void push(int x) {
        if((!maxST.empty() && x >= maxST.top()) ||maxST.empty()) {
            maxST.push(x);
        }
        allST.push(x);
    }
    
    int pop() {
        int x = allST.top();
        if(!allST.empty() && !maxST.empty() && allST.top() == maxST.top()) {
            allST.pop();
            maxST.pop();
            return x;
        }
        allST.pop();
        return x;
    }
    
    int top() {
        if(!allST.empty()) {
            int x = allST.top();
            return x;
        }
        return -1;
    }
    
    int peekMax() {
        if(!maxST.empty()) {
            int x = maxST.top();
            return x;
        }
        return -1;
    }
    
    int popMax() {
        int max = maxST.top();
        stack<int> tmp;
        while(allST.top() != max) {
            tmp.push(allST.top());
            allST.pop();
        }
        maxST.pop();
        allST.pop();
        while(!tmp.empty()) {
            push(tmp.top());
            tmp.pop();
        }
        return max;
    }
    //5 1 5
    //5 5
};
