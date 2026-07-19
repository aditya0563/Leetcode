class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        stack<int> st;
        vector<int> res(n);

        res[n-1]=0;
        st.push(n-1);

        for(int i=n-2;i>=0;i--){
            while(!st.empty() && temperatures[st.top()]<=temperatures[i]) st.pop();
            if(st.empty()) res[i]=0;
            else res[i]=st.top()-i;
            st.push(i);
        }

        return res;
    }
};