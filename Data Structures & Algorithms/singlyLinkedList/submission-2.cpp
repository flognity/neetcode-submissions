class LinkedList {
private:
    struct ListNode {
        int val;
        std::unique_ptr<ListNode> next;
        ListNode(int _val) : val(_val), next(nullptr) {}
    };

    std::unique_ptr<ListNode> head;
    int size;
public:
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    int get(int index) {
        // validate index
        if(index < 0 || index >= size)
            return -1;

        auto *node = head.get();
        int pos = 0;
        while(pos < index) {
            node = node->next.get();
            ++pos;
        }

        return node->val;
    }

    void insertHead(int val) {
        auto newNode = std::make_unique<ListNode>(val);

        // make the new node the new head and link it to the old head
        newNode->next = std::move(head);
        head = std::move(newNode);

        // size has increased
        ++size;
    }
    
    void insertTail(int val) {
        // for size 0, head and tail are the same
        if(size == 0) {
            insertHead(val);
            return;
        }
        
        auto newNode = std::make_unique<ListNode>(val);

        // get the last node
        auto node = head.get();
        while(node->next != nullptr) {
            node = node->next.get();
        }

        // we now have the last node
        // attach the new node at the end
        node->next = std::move(newNode);

        // size has increased
        ++size;
    }

    bool remove(int index) {
        // validate index
        if(index < 0 || index >= size)
            return false;

        if(index == 0) {
            head = std::move(head->next);
        } else {
            // find the node before the index
            auto prevNode = head.get();
            int pos = 0;
            while(pos < index - 1) {
                prevNode = prevNode->next.get();
                ++pos;
            }
            // bypass the node at index
            prevNode->next = std::move(prevNode->next->next);
        }
        
        --size;
        return true;
    }

    vector<int> getValues() {
        vector<int> values;
        if(size <= 0)
            return values;
        
        auto node = head.get();
        while(node != nullptr) {
            values.push_back(node->val);
            node = node->next.get();
        }

        return values;
    }
};