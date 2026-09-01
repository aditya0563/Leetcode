class LRUCache {
public:
    int capacity;
    list<pair<int, int>> cache_list;
    unordered_map<int, list<pair<int, int>>::iterator> cache_map;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache_map.find(key) == cache_map.end()) {
            return -1;
        }
        cache_list.splice(cache_list.begin(), cache_list, cache_map[key]);
        return cache_map[key]->second;
    }
    
    void put(int key, int value) {
        if (cache_map.find(key) != cache_map.end()) {
            cache_map[key]->second = value;
            cache_list.splice(cache_list.begin(), cache_list, cache_map[key]);
        } else {
            if (cache_list.size() == capacity) {
                int lru_key = cache_list.back().first;
                cache_list.pop_back();
                cache_map.erase(lru_key);
            }
            cache_list.push_front({key, value});
            cache_map[key] = cache_list.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */