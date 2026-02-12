class Solution {
    public int maximumWealth(int[][] accounts) {
        int wealth = 0;
        for(int[] cust : accounts){
            int current = 0;
            for(int bank : cust){
                current += bank;
            }
            wealth = Math.max(wealth, current);
        }

        return wealth;
    }
}