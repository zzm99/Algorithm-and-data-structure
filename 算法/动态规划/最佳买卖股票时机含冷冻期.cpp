// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(3));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        for(int i=1; i<prices.size(); i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][2]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
            dp[i][2] = dp[i-1][1]+prices[i];
        }
        return max(dp[prices.size()-1][0], dp[prices.size()-1][2]);
    }
};