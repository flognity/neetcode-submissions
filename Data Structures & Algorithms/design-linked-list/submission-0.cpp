class MyLinkedList {
public:
    MyLinkedList() {
        m_count = 0;
        m_pHead = nullptr;
        m_pTail = nullptr;
    }

    ~MyLinkedList() {
        while (m_pHead != nullptr) {
            ListNode *pNext = m_pHead->next;
            delete m_pHead;
            m_pHead = pNext;
        }
        m_count = 0;
        m_pTail = nullptr;
    }
    
    int get(int index) {
        int invalidReturn = -1;
        if(index < 0 || index >= m_count)
            return invalidReturn;

        // start at the had and iterate until the index-th node
        ListNode *pNode = m_pHead;
        for(int i = 0; i < index; ++i) {
            if(pNode->next != nullptr)
                pNode = pNode->next;
            else
                return invalidReturn;
        }
        return pNode->val;
    }
    
    void addAtHead(int val) {
        ListNode *pNewNode = new ListNode();
        pNewNode->val = val;
        pNewNode->next = m_pHead;

        // update the previous pointer of the old head
        if (m_pHead)
            m_pHead->prev = pNewNode;
        else
            m_pTail = pNewNode;

        // update the new head
        m_pHead = pNewNode;
        ++m_count;
    }
    
    void addAtTail(int val) {
        if(m_count == 0) {
            addAtHead(val);
            return;
        }

        if(m_pTail == nullptr) {
            // find the tail
            ListNode *pNode = m_pHead;
            while(pNode->next != nullptr)
                pNode = pNode->next;
            m_pTail = pNode;
        }

        ListNode *pNewNode = new ListNode();
        pNewNode->val = val;
        pNewNode->prev = m_pTail;

        // update the next pointer of the old tail
        m_pTail->next = pNewNode;

        // update the new tail
        m_pTail = pNewNode;
        ++m_count;
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        if (index == m_count)
        {
            addAtTail(val);
            return;
        }
        if (index < 0 || index > m_count)
            return;

        ListNode *pCurrentNode;
        // start at head and iterate until we reach index i
        pCurrentNode = m_pHead;
        int i;
        for(i = 0; i < index; ++i) {
            if(pCurrentNode->next != nullptr)
                pCurrentNode = pCurrentNode->next;
            else
                break;
        }

        // validate that we reached the index
        if(i < index && i > 0)
            return;

        // pCurrentNode is now at the i-th index. Insert before that
        ListNode *pNewNode = new ListNode();
        pNewNode->val = val;
        pNewNode->next = pCurrentNode;
        pNewNode->prev = pCurrentNode->prev;
        if (pCurrentNode->prev)
            pCurrentNode->prev->next = pNewNode;
        // update the counter
        ++m_count;
        //update the pCurrentNode
        pCurrentNode->prev = pNewNode;
    }
    
    void deleteAtIndex(int index) {
        // validate the index
        if (index < 0 || index >= m_count)
            return;

        ListNode *pCurrentNode;
        // start at head and iterate until we reach index i
        pCurrentNode = m_pHead;
        int i;
        for(i = 0; i < index; ++i) {
            if(pCurrentNode->next != nullptr)
                pCurrentNode = pCurrentNode->next;
            else
                break;
        }
        
        // validate that we reached the index
        if(i < index && i > 0)
            return;

        // pCurrentNode is now at the i-th index
        // before deletion, update pointers
        if (pCurrentNode->next != nullptr)
            pCurrentNode->next->prev = pCurrentNode->prev;
        else
            m_pTail = pCurrentNode->prev;

        if (pCurrentNode->prev != nullptr)
            pCurrentNode->prev->next = pCurrentNode->next;
        else
            m_pHead = pCurrentNode->next;

        // delete the current one
        delete pCurrentNode;

        // decrement the counter
        --m_count;
    }

private:
    struct ListNode {
        int val;
        ListNode* next = nullptr;
        ListNode* prev = nullptr;
    };

    ListNode *m_pHead;
    ListNode *m_pTail;
    int       m_count;
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