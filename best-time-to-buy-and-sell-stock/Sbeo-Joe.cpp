class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int lowest = prices[0];
        int ret = 0;
        for(int i = 1; i < prices.size(); i++){
            int& current_price = prices[i];
            if(current_price < lowest) {
                lowest = current_price;
            } else {
                ret = max(ret, current_price - lowest);
            }
        }
        return ret;
    }
};