class LRUCache {
public:
    LRUCache(int capacity) {
        maxSize = capacity;
    }
    
    int get(int key) {
        if(hashMap.contains(key)) {
            // get the value
            auto it = hashMap[key];
            int retValue = it->second;
            // remove the node
            linkedList.erase(it);
            // add to the back
            linkedList.push_back({key, retValue});
            // update the hashMap
            hashMap[key] = --linkedList.end();

            return retValue;
        } else {
            return -1;
        }
        
    }
    
    void put(int key, int value) {
        if(hashMap.contains(key)) {
            auto it = hashMap[key];
            // remove the node
            linkedList.erase(it);
        } else if(hashMap.size() == maxSize) {
            // if we are at capacity we need to pop the least used one (front)
            auto nodePair = linkedList.front();
            hashMap.erase(nodePair.first);
            linkedList.pop_front();
        }

        // add to the back
        linkedList.push_back({key, value});
        // update the hashMap
        hashMap[key] = --linkedList.end();
    }
private:
    int maxSize;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> hashMap;
    std::list<std::pair<int, int>> linkedList;
};
