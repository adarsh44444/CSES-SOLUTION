class Solution {
public:
    #define ll long long

    bool isPrime(ll n) {
        if (n <= 1) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (ll i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }

    long long sumOfLargestPrimes(string s) {
        set<ll> primes;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            string temp = "";
            for (int j = i; j < n; ++j) {
                temp += s[j];
                if (temp[0] == '0') continue; // Skip numbers with leading zero
                ll num = stoll(temp);
                if (isPrime(num)) {
                    primes.insert(num);
                }
            }
        }

        vector<ll> all(primes.begin(), primes.end());
        sort(all.rbegin(), all.rend()); // Descending order

        ll ans = 0;
        for (int i = 0; i < min(3, (int)all.size()); ++i) {
            ans += all[i];
        }

        return ans;
    }
};
