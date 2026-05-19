class Solution {
public:
    // int coinChange(vector<int>& coins, int amount) {
    //     int no_coins = 0;
    //     sort(coins.begin(),coins.end());
    //     int c = coins.size()-1;
    //     int rem_amount = amount;
    //     while(c >= 0){
    //         while((rem_amount-coins[c]) >= 0){
    //             rem_amount -= coins[c];
    //             no_coins++;
    //             if(rem_amount < 0){
    //                 rem_amount = amount;
    //             }
    //             if(rem_amount == 0){
    //                 return no_coins;
    //             }
    //         }
            
    //         c--;
    //     }
    //     return rem_amount == 0? no_coins: -1;
    // }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        int n = amount;
        dp[0] = 0;
        for(int i = 0; i <= amount; i++){
           for(int coin: coins){
                if(i-coin>=0){
                    dp[i] = min(dp[i],1 + dp[i-coin]);
                }
                
           }
    }
    return dp[amount] > amount ? -1: dp[amount];
    }
};
