class Solution {
  public:
    bool canplace(vector<int> stalls, int cows, int minDist){
        int cowPlace = 0;
        cows--;
        for(int i = 0; i<stalls.size() && cows > 0; i++){
            int locationOfLastCow = stalls[cowPlace];
            if(stalls[i] - locationOfLastCow >= minDist){
                cows--;
                cowPlace = i;
            }
        }
        return cows == 0;
    }
    
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        int rangeMax = stalls[stalls.size() - 1] - stalls[0];
        int mini = 1, ans = 1;
        while(mini <= rangeMax){
            int mid = mini + (rangeMax - mini) / 2;
            bool isPossible = canplace(stalls, k, mid);
            if(isPossible){
                mini = mid + 1;
                ans = mid;
            } else {
                rangeMax = mid - 1;
            }
        }
        return ans;
        
    }
};