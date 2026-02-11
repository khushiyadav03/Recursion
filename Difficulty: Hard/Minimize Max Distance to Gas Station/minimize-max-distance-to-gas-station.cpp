class Solution {
public:
    bool canPlace(vector<int> &stations, int K, double dist) {
        int required = 0;
        
        for(int i = 1; i < stations.size(); i++) {
            double gap = stations[i] - stations[i - 1];
            
            required += (int)(ceil(gap / dist) - 1);
            
            if(required > K) return false;
        }
        
        return required <= K;
    }
    
    double minMaxDist(vector<int> &stations, int K) {
        double low = 0;
        double high = 0;
        
        for(int i = 1; i < stations.size(); i++) {
            high = max(high, (double)(stations[i] - stations[i - 1]));
        }
        
        double ans = high;
        
        while(high - low > 1e-7) {  // precision control
            double mid = (low + high) / 2.0;
            
            if(canPlace(stations, K, mid)) {
                ans = mid;
                high = mid;
            } else {
                low = mid;
            }
        }
        
        return ans;
    }
};
