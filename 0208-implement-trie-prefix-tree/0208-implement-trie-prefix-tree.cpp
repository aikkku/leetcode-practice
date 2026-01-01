class Node {
public:
    unordered_map<char, Node*> children;
    bool word;

    Node() {
        word = false;
    }
};

class Trie {
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* cur = root;

        for(int i = 0; i < word.length(); i++) {
            if(cur->children.find(word[i]) == cur->children.end()) {
                cur->children[word[i]] = new Node();
            }
            cur = cur->children[word[i]];
        }

        cur->word = true;
    }
    
    bool search(string word) {
        Node* cur = root;
        for(int i = 0; i < word.length(); i++) {
            if(cur->children.find(word[i]) == cur->children.end()) {
                return false;
            }
            cur = cur->children[word[i]];
        }

        return cur->word;
    }
    
    bool startsWith(string prefix) {
        Node* cur = root;
        for(int i = 0; i < prefix.length(); i++) {
            if(cur->children.find(prefix[i]) == cur->children.end()) {
                return false;
            }
            cur = cur->children[prefix[i]];
        }

        return true;
    }

private:
    Node* root;
};
