class Solution {
  public:
    void reverseStack(stack<int> &st) {
        vector<int> arr;
        while(!st.empty()){
            arr.push_back(st.top());
            st.pop();
        }
        for(int x : arr){
            st.push(x);
        }
    }
};