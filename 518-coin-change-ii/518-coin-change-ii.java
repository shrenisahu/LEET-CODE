class Solution {
    public int change(int amount, int[] coins) {
      return totalWays(coins, 0, amount, new HashMap<String,Integer>());
    }
    public int totalWays(int[] coins, int currentIndex, int amount, HashMap<String,Integer> memo){
        if(amount==0)
            return 1;
        if(currentIndex >= coins.length)
            return 0; 
        
        String currentKey = Integer.toString(currentIndex) + "_" + Integer.toString(amount);
        
        if(memo.containsKey(currentKey)){
            return memo.get(currentKey);
        }
        
        int consider = 0; 
        if(coins[currentIndex] <= amount){
            consider = totalWays(coins, currentIndex, amount - coins[currentIndex], memo);
        }
        
        int notConsider = totalWays(coins, currentIndex + 1, amount, memo);
        
        memo.put(currentKey, consider + notConsider);
        
        return memo.get(currentKey); 
    }
}