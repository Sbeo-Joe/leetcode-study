class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        
        if (strs.empty()) {
            return ret;
        }
        
        unordered_map<string, vector<string>> um;

        for (const string& str : strs) {
            string s = str;
            sort(s.begin(), s.end()); 
            um[s].push_back(str);
        }

        for (const auto& p : um) {
            ret.push_back(p.second);
        }

        return ret;
    }
};