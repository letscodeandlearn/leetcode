class Solution {
    public int coinChange(int[] coins, int amount) {
       int[] result = new int[amount + 1];
        Arrays.fill(result, Integer.MAX_VALUE);
        result[0] = 0;
        
        for (int i = 0; i <= amount; i++) {
            for (int j = 0; j < coins.length; j++) {
                if (i + coins[j] <= amount &&
                    result[i + coins[j]] == Integer.MAX_VALUE) {
                    result[i + coins[j]] = 1 + result[i];
                } else if(result[amount] != Integer.MAX_VALUE) {
                    break;
                }
            }
        }
        return result[amount] >= Integer.MAX_VALUE? -1 : result[amount];
    }
}