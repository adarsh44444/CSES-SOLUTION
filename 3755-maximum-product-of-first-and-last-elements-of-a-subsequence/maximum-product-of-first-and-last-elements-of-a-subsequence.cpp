class Solution {
public:
    #define ll long long
    vector<ll> segtree, segtre;

    void buildsegtree(int i, int l, int r, vector<int>& nums) {
        if (l == r) {
            segtree[i] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        buildsegtree(2 * i + 1, l, mid, nums);
        buildsegtree(2 * i + 2, mid + 1, r, nums);
        segtree[i] = max(segtree[2 * i + 1], segtree[2 * i + 2]);
    }

    ll query(ll start, ll end, ll i, ll l, ll r) {
        if (r < start || l > end) return LLONG_MIN;
        if (l >= start && r <= end) return segtree[i];
        ll mid = (l + r) / 2;
        return max(query(start, end, 2 * i + 1, l, mid),
                   query(start, end, 2 * i + 2, mid + 1, r));
    }

    void buildsegtre(int i, int l, int r, vector<int>& nums) {
        if (l == r) {
            segtre[i] = nums[l];
            return;
        }
        int mid = (l + r) / 2;
        buildsegtre(2 * i + 1, l, mid, nums);
        buildsegtre(2 * i + 2, mid + 1, r, nums);
        segtre[i] = min(segtre[2 * i + 1], segtre[2 * i + 2]);
    }

    ll quer(ll start, ll end, ll i, ll l, ll r) {
        if (r < start || l > end) return LLONG_MAX;
        if (l >= start && r <= end) return segtre[i];
        ll mid = (l + r) / 2;
        return min(quer(start, end, 2 * i + 1, l, mid),
                   quer(start, end, 2 * i + 2, mid + 1, r));
    }

    long long maximumProduct(vector<int>& nums, int m) {
        ll n = nums.size();
        segtree.assign(4 * n, 0);
        segtre.assign(4 * n, 0);
        buildsegtree(0, 0, n - 1, nums);
        buildsegtre(0, 0, n - 1, nums);
        ll ans = LLONG_MIN;

        for (int i = 0; i <= n - m; i++) {
            if (nums[i] > 0) {
                ll temp1 = query(i + m - 1, n - 1, 0, 0, n - 1);
                ans = max(ans, temp1 * 1LL * nums[i]);
            } else {
                ll temp2 = quer(i + m - 1, n - 1, 0, 0, n - 1);
                ans = max(ans, temp2 * 1LL * nums[i]);
            }
        }
        return ans;
    }
};
