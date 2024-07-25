#include <set>
#include <tuple>
#include <functional>
#include <map>

class LRU {
    std::set<int, std::function<bool(int, int)>> s;
    std::map<int, int> time, cache;
    int capacity;
    int t = 0;
public: 
    LRU(int capacity) : capacity(capacity) {
        auto cmp = [&](int a, int b) {
            return time[a] < time[b];
        };
        s = std::set<int, std::function<bool(int, int)>>(cmp);
    }
    int get(int key) {
        if(!cache.count(key)) return -1;
        s.erase(key);
        time[key] = t++;
        s.insert(key);
        return cache[key];
    }
    void put(int key, int value) {
        if(cache.count(key)){
            get(key);
            cache[key] = value;
            return;
        }
        if(cache.size() == capacity) {
            auto it = s.begin();
            time.erase(*it);
            cache.erase(*it);
            s.erase(it);
        }
        time[key] = t++;
        cache[key] = value;
        s.insert(key);
    }
};

int main() {

}
