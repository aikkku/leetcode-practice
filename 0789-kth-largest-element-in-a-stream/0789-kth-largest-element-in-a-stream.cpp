class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        heap.push_back(0);
        for(int i : nums) {
            add(i);
        }
    }

    void pop() {
    if (heap.size() <= 1) return;

    heap[1] = heap.back();
    heap.pop_back();

    int i = 1;
    int n = heap.size();

    while (2 * i < n) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int smallest = i;

        if (left < n && heap[left] < heap[smallest])
            smallest = left;
        if (right < n && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i) break;

        swap(heap[i], heap[smallest]);
        i = smallest;
    }
}

    
    int add(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;
        while (i > 1 && heap[i] < heap[i / 2]) {
            swap(heap[i], heap[i / 2]);
            i /= 2;
        }

        if (heap.size() - 1 > k) {
            pop();
        }

        return heap[1]; 
    }

private:
    vector<int> heap;
    int k;
};
