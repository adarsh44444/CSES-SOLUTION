#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void findpermut(vector<int> &ds, vector<int> &strength, vector<int> &freq, int &ans1, int k) {
        if (ds.size() == strength.size()) {
            int time = 0, x = 1;
            for (int it1 : ds) {
                time += ceil((1.0 * it1) / x);
                x += k;
            }
            ans1 = min(ans1, time);
            return;
        }
        for (int i = 0; i < strength.size(); i++) {
            if (!freq[i]) {
                ds.push_back(strength[i]);
                freq[i] = 1;
                findpermut(ds, strength, freq, ans1, k);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

    int findMinimumTime(vector<int> &strength, int k) {
        int n = strength.size();
        vector<int> freq(n, 0), ds;
        int ans1 = INT_MAX;
        findpermut(ds, strength, freq, ans1, k);
        return ans1;
    }
};
