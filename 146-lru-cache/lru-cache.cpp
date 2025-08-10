class LRUCache {
    int cap;
    list<pair<int,int>> DL; // Doubly Linked List
    unordered_map<int, list<pair<int,int>>::iterator> pos; // Map: key -> iterator

public:
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        auto it = pos.find(key);
        if (it == pos.end()) return -1;
        DL.splice(DL.begin(), DL, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = pos.find(key);
        if (it != pos.end()) {
            it->second->second = value;
            DL.splice(DL.begin(), DL, it->second);
            return;
        }
        if ((int)DL.size() == cap) {
            pos.erase(DL.back().first);
            DL.pop_back();
        }
        DL.emplace_front(key, value);
        pos[key] = DL.begin();
    }
};
