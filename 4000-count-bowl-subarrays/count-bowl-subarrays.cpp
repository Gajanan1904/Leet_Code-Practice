class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, -1), right(n, -1);
        stack<int> st;

        // Nearest Greater Left
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                left[i] = st.top();
            }

            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                right[i] = st.top();
            }

            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            if (left[i] != -1 && i - left[i] >= 2) ans++;
            if (right[i] != -1 && right[i] - i >= 2) ans++;
        }

        return ans;
    }
};