class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;

        for(int i = 0; i < n; i++) {
            vector<int> freq(26, 0);

            for(int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int firstFreq = 0;
                bool balanced = true;

                for(int k = 0; k < 26; k++) {
                    if(freq[k] > 0) {
                        if(firstFreq == 0) {
                            firstFreq = freq[k];
                        } 
                        else if(freq[k] != firstFreq) {
                            balanced = false;
                            break;
                        }
                    }
                }

                if(balanced) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};
