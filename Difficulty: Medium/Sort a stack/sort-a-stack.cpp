class Solution {
  public:
    void insertedSort(stack<int> &st, int x){
        if(st.empty() || st.top() <= x){
            st.push(x);
            return;
        }
        int temp = st.top();
        st.pop();
        insertedSort(st, x);
        st.push(temp);
    }
    
    void sortStack(stack<int> &st) {
        if(st.empty()) return;
        int top = st.top();
        st.pop();
        sortStack(st);
        insertedSort(st, top);
    }
};
