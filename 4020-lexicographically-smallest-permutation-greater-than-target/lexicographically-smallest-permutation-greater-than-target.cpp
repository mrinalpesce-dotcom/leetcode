class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string ans = "";

        // Try to match target from left to right
        for (int i = 0; i < target.size(); i++) {

            int x = target[i] - 'a';

            // We can use target[i]
            if (freq[x] > 0) {

                ans += target[i];
                freq[x]--;

            } else {

                // We cannot match target[i].
                // Try the smallest character greater than it.
                for (int c = x + 1; c < 26; c++) {

                    if (freq[c] > 0) {

                        ans += char('a' + c);
                        freq[c]--;

                        // Remaining characters in sorted order
                        for (int j = 0; j < 26; j++) {
                            while (freq[j] > 0) {
                                ans += char('a' + j);
                                freq[j]--;
                            }
                        }

                        return ans;
                    }
                }

                // No greater character here.
                // We need to go back and change an earlier character.
                break;
            }
        }

        // Backtracking from the right
        freq.assign(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        for (int i = target.size() - 1; i >= 0; i--) {

            // Use target[0 ... i-1]
            bool possible = true;

            for (int j = 0; j < i; j++) {

                if (freq[target[j] - 'a'] == 0) {
                    possible = false;
                    break;
                }

                freq[target[j] - 'a']--;
            }

            if (!possible) {
                freq.assign(26, 0);

                for (char c : s)
                    freq[c - 'a']++;

                continue;
            }

            int x = target[i] - 'a';

            // Find smallest character greater than target[i]
            for (int c = x + 1; c < 26; c++) {

                if (freq[c] > 0) {

                    string result = target.substr(0, i);
                    result += char('a' + c);

                    freq[c]--;

                    for (int j = 0; j < 26; j++) {
                        while (freq[j] > 0) {
                            result += char('a' + j);
                            freq[j]--;
                        }
                    }

                    return result;
                }
            }

            freq.assign(26, 0);

            for (char c : s)
                freq[c - 'a']++;
        }

        return "";
    }
};