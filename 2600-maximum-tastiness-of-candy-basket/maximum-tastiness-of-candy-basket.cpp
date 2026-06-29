class Solution {
public:
    bool check(vector<int>& price, int k, int diff) {
        int cnt = 1;
        int last = price[0];

        for (int i = 1; i < price.size(); i++) {
            if (price[i] - last >= diff) {
                cnt++;
                last = price[i];
            }
        }

        return cnt >= k;
    }

    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());

        int l = 0, r = price.back() - price.front();
        int ans = 0;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (check(price, k, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};