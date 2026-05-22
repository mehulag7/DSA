class Solution {
    // Map to store the level/step of each word from beginWord
    unordered_map<string, int> mpp;
    vector<vector<string>> ans;
    string bWord;

private:
    void dfs(string word, vector<string>& seq) {
        // Base condition: If we reach the beginWord, we stop
        if (word == bWord) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end()); // Reverse back for backtracking
            return;
        }

        int steps = mpp[word];
        int sz = word.size();

        // Try replacing every character to find the parent word
        for (int i = 0; i < sz; i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                // If the transformed word exists in map and belongs to the previous level
                if (mpp.find(word) != mpp.end() && mpp[word] == steps - 1) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back(); // Backtrack
                }
            }
            word[i] = original; // Undo change
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        
        bWord = beginWord;
        q.push(beginWord);
        mpp[beginWord] = 1;
        st.erase(beginWord); // Remove beginWord so we don't loop back to it

        int sz = beginWord.size();

        // BFS to find the shortest distance levels for each word
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int steps = mpp[word];

            // If we reach the endWord, we don't need to look for deeper levels
            if (word == endWord) break;

            for (int i = 0; i < sz; i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.count(word)) {
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps + 1; // Assign step level
                    }
                }
                word[i] = original; // Undo change
            }
        }

        // If endWord was reached during BFS, trace back paths using DFS
        if (mpp.find(endWord) != mpp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }

        return ans;
    }
};