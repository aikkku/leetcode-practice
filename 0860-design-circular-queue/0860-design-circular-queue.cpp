class MyCircularQueue {
public:
    struct Node {
        Node(int val) {
            this->val = val;
        }

        int val;
        Node* next = nullptr;
    };

    MyCircularQueue(int k) {
        size = k;
        count = 0;
        head = new Node(-1);
        head->next = head;
    }
    
    bool enQueue(int value) {
        if(count == size) return false;

        Node* dummy = new Node(value);
        

        Node* cur = head;
        while(cur->next->val != -1) {
            cur = cur->next;
        }
        cur->next = dummy;
        dummy->next = head;
        count++;

        return true;
    }
    
    bool deQueue() {
        if(count == 0) return false;

        Node* todelete = head->next;
        head->next = todelete->next;
        delete todelete;
        count--;
        
        return true;
    }
    
    int Front() {
        return head->next->val;
    }
    
    int Rear() {
        Node* cur = head;
        while(cur->next->val != -1) {
            cur = cur->next;
        }

        return cur->val;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == size;
    }

    int size; 
    int count;
    Node* head;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */