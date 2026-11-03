class Deque {
private:
    struct ListNode {
        int val;
        ListNode *next = nullptr;
        ListNode *prev = nullptr;
    };

    ListNode *m_head = nullptr;
    ListNode *m_tail = nullptr;
public:
    Deque() {
    }
    ~Deque() {
        while (m_head) {
            ListNode *temp = m_head;
            m_head = m_head->next;
            delete temp;
        }

    }

    bool isEmpty() {
        return m_head == nullptr;
    }

    void append(int value) {
        ListNode *newNode = new ListNode();
        newNode->val = value;

        if(m_tail) {
            // new node will become the new tail
            m_tail->next = newNode;
            newNode->prev = m_tail;
            m_tail = newNode;
        } else if(m_head) {
            // tail does not exist, but head does
            m_head->next = newNode;
            newNode->prev = m_head;
            m_tail = newNode;
        }
        else {
            // both, head and tail don't exist
            m_head = newNode;
            m_tail = newNode;
        }
    }

    void appendleft(int value) {
        ListNode *newNode = new ListNode();
        newNode->val = value;

        if(m_head) {
            // new node will become the new head
            newNode->next = m_head;
            m_head->prev = newNode;
            m_head = newNode;
        } else {
            // head doesn't exist yet
            m_head = newNode;
            m_tail = newNode;
        }
    }

    int pop() {
        int retVal = -1;
        if(m_tail != nullptr) {
            retVal = m_tail->val;
            // delete the current tail
            ListNode *newTail = m_tail->prev;
            if(newTail != nullptr)
            {
                newTail->next = nullptr;
                // delete the current tail
                delete m_tail;
            }
            else
            {
                delete m_head;
                m_head = nullptr;
            }

            // assign the new tail
            m_tail = newTail;
        } else if (m_head) {
            retVal = m_head->val;
            delete m_head;
        }

        return retVal;
    }

    int popleft() {
        int retVal = -1;
        if(m_head != nullptr) {
            retVal = m_head->val;
            ListNode *newHead = m_head->next;
            if(newHead != nullptr)
            {
                newHead->prev = nullptr;
                delete m_head; 
            }
            else
            {
                delete m_tail;
                m_tail = nullptr;
            }

            m_head = newHead;
        }

        return retVal;
    }
};
