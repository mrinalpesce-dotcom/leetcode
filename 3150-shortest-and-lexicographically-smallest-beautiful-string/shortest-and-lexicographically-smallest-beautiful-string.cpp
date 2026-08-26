class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        int left = 0;
        int count = 0;

        string ans = "";

        for (int right = 0; right < s.size(); right++) {

            // Add current character
            if (s[right] == '1') {
                count++;
            }

            // If we have more than k ones,
            // move left until we have k ones again
            while (count > k) {

                if (s[left] == '1') {
                    count--;
                }

                left++;
            }

            // Now count is exactly k
            if (count == k) {

                // Remove unnecessary zeros from the left
                while (s[left] == '0') {
                    left++;
                }

                string current = s.substr(left, right - left + 1);

                // First valid answer
                if (ans == "") {
                    ans = current;
                }

                // Shorter substring
                else if (current.length() < ans.length()) {
                    ans = current;
                }

                // Same length -> lexicographically smaller
                else if (current.length() == ans.length() &&
                         current < ans) {
                    ans = current;
                }
            }
        }

        return ans;
    }
};