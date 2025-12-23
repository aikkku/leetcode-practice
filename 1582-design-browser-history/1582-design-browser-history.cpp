class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        val = homepage;
        curr = this;
    }
    
    void visit(string url) {
        BrowserHistory* temp = new BrowserHistory(url);
        curr->next = temp;
        temp->prev = curr;
        curr = temp;
    }
    
    string back(int steps) {
        while(curr->prev and steps > 0) {
            curr = curr->prev;
            steps--;
        }

        return curr->val;
    }
    
    string forward(int steps) {
        while(curr->next and steps > 0) {
            curr = curr->next;
            steps--;
        }

        return curr->val;
    }

private:
    string val;
    BrowserHistory* next = nullptr;
    BrowserHistory* prev = nullptr;
    BrowserHistory* curr = nullptr;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */