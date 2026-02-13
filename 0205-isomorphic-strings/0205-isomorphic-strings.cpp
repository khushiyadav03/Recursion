class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> map1(256, -1); // s->t
        vector<int> map2(256, -1); // t->s
        for(int i =0; i<s.length(); i++){
            char c1 = s[i];
            char c2 = t[i];

            if(map1[c1] == -1 && map2[c2] == -1){
                map1[c1] = c2;
                map2[c2] = c1;
            } else if(map1[c1] != c2){
                return false;
            }
        }
        return true;
    }
};