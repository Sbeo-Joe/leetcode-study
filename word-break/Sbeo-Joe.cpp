class Solution {
public:
    int dp[301];
    bool wordBreak(string s, vector<string>& wordDict) {
        
        memset(dp, -1, sizeof(dp));
        auto ret =  solve(0, s, wordDict);
        // for(int i = 0; i <= s.size(); i++){
        //     cout << dp[i] << " ";
        // }
        return (dp[0] == 1);
    }

    int solve(int here, string &s, vector<string>& wordDict) {
        if(here == s.size()) return 1;
        // if(here > s.size()) return 0;
        int& ret = dp[here];
        if(ret != -1) return ret;
        ret = 0;

        for(string& word : wordDict){
            int i;
            for(i = 0; i < word.size(); i++){
                if(s[here + i] != word[i])
                    break;
            }
            if(i == word.size()){
                ret = ret || solve(here + word.size(), s, wordDict);
                // cout << here << " " << word<< " " << ret << endl;
            }
        }

        return ret;
    }
};