class Solution {
  public:
    void sortStack(stack<int> &st) {
        vector<int> arr;
        while(!st.empty()){
            arr.push_back(st.top());
            st.pop();
        }
        sort(arr.begin(), arr.end());
        for (int x : arr) {
            st.push(x);
        }
    }
};
