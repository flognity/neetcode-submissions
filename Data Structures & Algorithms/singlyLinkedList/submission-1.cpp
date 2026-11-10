class LinkedList {
private:
    struct ListNode {
        int         val;
        ListNode*   next;
    };
    ListNode* head;
    ListNode* tail;
    int size;
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    ~LinkedList() {
        while (head != nullptr) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    int get(int index) {
        // validate index
        if (index < 0 || index >= size)
            return -1;
        ListNode* node = head; 
        int pos = 0;
        while (pos < index && node->next != nullptr) {
            node = node->next;
            ++pos;
        }

        return node->val; 
    }

    void insertHead(int val) {
        ListNode *newNode = new ListNode();
        newNode->val = val;
        newNode->next = head;
        head = newNode;
        if (size == 0) {
            tail = head;
        }

        // increment the size
        ++size;
    }
    
    void insertTail(int val) {
        ListNode *newNode = new ListNode();
        newNode->val = val;
        newNode->next = nullptr;
        if (size == 0) {
            // tail and head are the same
            head = newNode;
            tail = newNode;
        }
        else {
            // link old tail to the new node
            tail->next = newNode;
            // new node becomes the new tail
            tail = newNode;
        }

        // increment the size
        ++size;
    }

    bool remove(int index) {
        if (index < 0 || index >= size)
            return false;

        ListNode* node; 
        if (index == 0) {
            // intention is to delete the head
            node = head; 
            head = head->next;
            if (size == 1) {
                tail = nullptr;
            }
        } else {
            ListNode* prevNode = head;
            int pos = 0;
            while (pos < index - 1) {
                prevNode = prevNode->next;
                ++pos;
            }
            node = prevNode->next;
            prevNode->next = node->next;
            if (index == size - 1) {
                tail = prevNode;
            }
        }

        delete node;
        --size;

        return true;
    }

    vector<int> getValues() {
        vector<int> values;
        if(size <= 0)
            return values;
        
        ListNode* node = head;
        while(node != nullptr) {
            values.push_back(node->val);
            node = node->next;
        }

        return values;
    }
};
