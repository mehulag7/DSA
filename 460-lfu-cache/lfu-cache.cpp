class LFUCache {
public:

    struct Node {
        int key, val, freq;
    };

    int cap;
    int minFreq;

    unordered_map<int, list<Node>::iterator> mp;
    unordered_map<int, list<Node>> freqList;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }
    
    int get(int key) {

        if(mp.find(key) == mp.end())
            return -1;

        auto it = mp[key];
        Node node = *it;

        // remove from current freq list
        freqList[node.freq].erase(it);

        if(freqList[node.freq].empty()){
            freqList.erase(node.freq);
            if(minFreq == node.freq)
                minFreq++;
        }

        // increase freq
        node.freq++;
        freqList[node.freq].push_front(node);
        mp[key] = freqList[node.freq].begin();

        return node.val;
    }
    
    void put(int key, int value) {

        if(cap == 0) return;

        if(mp.find(key) != mp.end()){
            // update value
            mp[key]->val = value;
            get(key); // update freq
            return;
        }

        if(mp.size() == cap){
            // remove LFU
            auto &listRef = freqList[minFreq];
            auto node = listRef.back();

            mp.erase(node.key);
            listRef.pop_back();

            if(listRef.empty())
                freqList.erase(minFreq);
        }

        // insert new node
        Node node = {key, value, 1};
        freqList[1].push_front(node);
        mp[key] = freqList[1].begin();
        minFreq = 1;
    }
};