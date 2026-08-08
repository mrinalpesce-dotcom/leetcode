class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // pre[i] = maximum number of characters
        // of word2 that can be matched using word1[0...i]
        vector<int> pre(n);

        int j = 0;

        for (int i = 0; i < n; i++) {
            if (j < m && word1[i] == word2[j]) {
                j++;
            }

            pre[i] = j;
        }

        // suf[i] = minimum index in word2 from which
        // word1[i...] can match word2 exactly.
        vector<int> suf(n + 1, m);

        j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                suf[i] = j;
                j--;
            } else {
                suf[i] = j + 1;
            }
        }

        vector<int> ans;

        j = 0;
        bool changed = false;

        for (int i = 0; i < n && j < m; i++) {

            // Exact match
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }

            // Use the one allowed mismatch
            else if (!changed) {

                // Check whether the remaining characters
                // can be matched after this index.
                if (i + 1 <= n && suf[i + 1] <= j + 1) {
                    ans.push_back(i);
                    j++;
                    changed = true;
                }
            }
        }

        if (j != m) {
            return {};
        }

        return ans;
    }
};