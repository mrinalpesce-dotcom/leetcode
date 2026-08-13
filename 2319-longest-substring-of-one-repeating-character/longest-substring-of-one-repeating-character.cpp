class Solution {
public:

    struct Node {
        char leftChar;
        char rightChar;

        int prefix;
        int suffix;
        int best;
        int len;

        Node() {
            leftChar = rightChar = '#';
            prefix = suffix = best = len = 0;
        }
    };

    vector<Node> seg;

    Node merge(Node a, Node b) {

        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        // Initially best comes from either side
        res.prefix = a.prefix;
        res.suffix = b.suffix;

        res.best = max(a.best, b.best);

        // If characters at the boundary are same,
        // we can join suffix of left + prefix of right
        if (a.rightChar == b.leftChar) {

            res.best = max(res.best,
                           a.suffix + b.prefix);

            // Entire left part has the same character
            if (a.prefix == a.len) {
                res.prefix = a.len + b.prefix;
            }

            // Entire right part has the same character
            if (b.suffix == b.len) {
                res.suffix = b.len + a.suffix;
            }
        }

        return res;
    }

    void build(int node, int l, int r, string &s) {

        if (l == r) {
            seg[node].leftChar = s[l];
            seg[node].rightChar = s[l];

            seg[node].prefix = 1;
            seg[node].suffix = 1;
            seg[node].best = 1;
            seg[node].len = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(2 * node, l, mid, s);
        build(2 * node + 1, mid + 1, r, s);

        seg[node] = merge(seg[2 * node],
                          seg[2 * node + 1]);
    }

    void update(int node, int l, int r,
                int idx, char ch) {

        if (l == r) {

            seg[node].leftChar = ch;
            seg[node].rightChar = ch;

            seg[node].prefix = 1;
            seg[node].suffix = 1;
            seg[node].best = 1;
            seg[node].len = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            update(2 * node, l, mid, idx, ch);
        }
        else {
            update(2 * node + 1, mid + 1, r, idx, ch);
        }

        seg[node] = merge(seg[2 * node],
                          seg[2 * node + 1]);
    }

    vector<int> longestRepeating(string s,
                                 string queryCharacters,
                                 vector<int>& queryIndices) {

        int n = s.size();

        seg.resize(4 * n + 5);

        build(1, 0, n - 1, s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            int idx = queryIndices[i];
            char ch = queryCharacters[i];

            update(1, 0, n - 1, idx, ch);

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};