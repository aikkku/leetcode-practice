class MyLinkedList {
public:
    MyLinkedList() {
        next = nullptr;
        val = 0;
        is_dummy = 1;
    }
    
    int get(int index) {
        MyLinkedList* cur = this;
        if(is_dummy) cur = cur->next;

        while(index > 0 and cur) {
            cur = cur->next;
            index--;
        }
        if(!cur) return -1;
        return cur->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        MyLinkedList* cur = this;
        while(cur->next) {
            cur = cur->next;
        }

        MyLinkedList* tail = new MyLinkedList();
        tail->is_dummy = false;
        tail->val = val;
        cur->next = tail;
    }
    
    void addAtIndex(int index, int val) {
        MyLinkedList* cur = this;
        while (index > 0 && cur->next != nullptr) {
            cur = cur->next;
            index--;
        }

        if (index == 0) {
            MyLinkedList* temp = new MyLinkedList();
            temp->is_dummy = false;
            temp->val = val;
            temp->next = cur->next;
            cur->next = temp;
        }
    }
    
    void deleteAtIndex(int index) {
        MyLinkedList* cur = this;
        while(index-- and cur->next) {
            cur = cur->next;
        }

        if(cur->next) {
            cur->next = cur->next->next;
        }
    }

private:
    MyLinkedList* next;
    int val;
    bool is_dummy = 0;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */