class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char,int> freq;

        // count frequency
        for(char c : s){
            freq[c]++;
        }

        // convert map to vector
        vector<pair<char,int>> vec(freq.begin(), freq.end());

        // sort by frequency descending
        sort(vec.begin(), vec.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });

        string result = "";

        // build string
        for(auto &p : vec){
            result += string(p.second, p.first);
        }

        return result;
    }
};