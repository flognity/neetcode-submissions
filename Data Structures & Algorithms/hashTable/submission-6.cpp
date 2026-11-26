class HashTable {
public:
    HashTable(int capacity) {
        maxSize = capacity;
        currentSize = 0;
        table.resize(maxSize, Pair());
    }

    void insert(int key, int value) {
        int idx = findValidIdx(key);

        if (idx != -1) {
            // this key already exists; overwrite the value
            table[idx].val = value;
            return;
        } else {
            // key does not exist yet, so we need to add it
            if ((currentSize + 1) >= (0.5 * maxSize)) {
                resize();
            }

            int origIdx = getIndex(key);
            int idx = origIdx;
            while(idx < maxSize && !table[idx].empty) {
                // check the next entry    
                ++idx;
            }

            // wrap around
            if(idx == maxSize) {
                idx = 0;
                while(idx < origIdx && !table[idx].empty) {
                    // check the next entry    
                    ++idx;
                }
            }

            // found our empty spot, now insert
            table[idx].key = key;
            table[idx].val = value;
            table[idx].empty = false;
            ++currentSize;
        }
    }

    int get(int key) {
        int idx = findValidIdx(key);
        if (idx != -1) 
            return table[idx].val;

        return -1;
    }

    bool remove(int key) {
        int idx = findValidIdx(key);

        if (idx != -1) {
            table[idx].empty = true;
            --currentSize;
            reHash();
            return true;
        }

        return false;
    }

    int getSize() const {
        return currentSize;
    }

    int getCapacity() const {
        return maxSize;
    }

    void resize() {
        maxSize *= 2;
        reHash();
    }
private:
    struct Pair {
        int key;
        int val;
        bool empty;
        Pair(int _key, int _val) : key(_key), val(_val), empty(false) {};
        Pair() : empty(true) {};
    };

    std::vector<Pair> table;
    int maxSize;
    int currentSize;

    int getIndex(int key) {
        return key % maxSize;
    }

    int findValidIdx(int key) {
        int origIdx = getIndex(key);
        int idx = origIdx;
        while(idx < maxSize && !table[idx].empty) {
            if(table[idx].key == key)
                return idx;
            // check the next entry    
            ++idx;
        }

        if (idx == maxSize) {
            // wrap around
            idx = 0;
            while(idx < origIdx && !table[idx].empty) {
                if(table[idx].key == key) {
                    return idx;
                }
                // check the next entry    
                ++idx;
            }
        }

        return -1;
    }

    void reHash() {
        std::vector<Pair> oldTable = table;
        table.clear();
        table.resize(maxSize, Pair());
        currentSize = 0;
        for(int i = 0; i < oldTable.size(); ++i) {
            if(!oldTable[i].empty)
                insert(oldTable[i].key, oldTable[i].val);
        }
    }
};
