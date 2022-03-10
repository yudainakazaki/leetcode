#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

class RandomizedSet {
private:
    set<int> s;
    
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if(s.find(val) != s.end()) return false;
        else {
            s.insert(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if(s.find(val) != s.end()) {
            s.erase(val);
            return true;
        }else return false;
    }
    
    int getRandom() {
        int index = rand()%s.size();
        auto itr = s.begin();
        for(int i = 0; i < index; i++) itr++;
        return *itr;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

int main() {
    
}

// O(N*E) where N is the size of the elements in the list and E is the length of an element