class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        multiset<int> st;
        long long ans = 0;
        int l = 0;

        for (int r = 0; r < nums.size(); r++) {
            st.insert(nums[r]);

            while (*st.rbegin() - *st.begin() > 2) {
                st.erase(st.find(nums[l]));
                l++;
            }

            ans += (r - l + 1);
        }

        return ans;
    }
};