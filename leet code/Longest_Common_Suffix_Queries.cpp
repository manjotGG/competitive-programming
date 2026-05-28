#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cstring>
using namespace std;
class Solution {
public:
    struct Node {
        int child[26];
        int bestIdx;

        Node() {
            memset(child, -1, sizeof(child));
            bestIdx = -1;
        }
    };

    vector<Node> trie;

    void updateBest(int &bestIdx, vector<string>& wordsContainer, int idx) {
        if (bestIdx == -1 ||
            wordsContainer[idx].size() < wordsContainer[bestIdx].size() ||
            (wordsContainer[idx].size() == wordsContainer[bestIdx].size() && idx < bestIdx)) {
            bestIdx = idx;
        }
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie.clear();

        // reserve memory to avoid runtime error
        int total = 1;
        for (auto &w : wordsContainer) {
            total += w.size();
        }
        trie.reserve(total);

        trie.emplace_back(); // root

        // Build trie
        for (int i = 0; i < wordsContainer.size(); i++) {
            int node = 0;

            updateBest(trie[node].bestIdx, wordsContainer, i);

            for (int j = wordsContainer[i].size() - 1; j >= 0; j--) {
                int c = wordsContainer[i][j] - 'a';

                if (trie[node].child[c] == -1) {
                    trie[node].child[c] = trie.size();
                    trie.emplace_back();
                }

                node = trie[node].child[c];
                updateBest(trie[node].bestIdx, wordsContainer, i);
            }
        }

        vector<int> ans;

        // Query
        for (auto &q : wordsQuery) {
            int node = 0;

            for (int j = q.size() - 1; j >= 0; j--) {
                int c = q[j] - 'a';

                if (trie[node].child[c] == -1) break;

                node = trie[node].child[c];
            }

            ans.push_back(trie[node].bestIdx);
        }

        return ans;
    }
};