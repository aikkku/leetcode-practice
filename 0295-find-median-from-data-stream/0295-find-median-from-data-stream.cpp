class MedianFinder {
public:
    MedianFinder() {}

    void addNum(int num) {
        small.push(num);

        if(!big.empty() and small.top() > big.top()) {
            big.push(small.top());
            small.pop();
        }

        if (small.size() > big.size() + 1) {
            big.push(small.top());
            small.pop();
        }
        if (big.size() > small.size() + 1) {
            small.push(big.top());
            big.pop();
        }
    }
    
    double findMedian() {
        if(small.size() > big.size()) return small.top();
        if(big.size() > small.size()) return big.top();
        return (small.top() + big.top()) / 2.0;
    }

    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<int>> big;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */