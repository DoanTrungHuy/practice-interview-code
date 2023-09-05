using ll = long long;
const int MN = 1e6 + 1;
ll p[MN];
const ll MOD = 1e9 + 7;

class Solution {
public:
    ll exp(ll a, ll b) {
        if (b == 0) {
            return 1;
        }
        ll res = exp(a, b / 2);
        res = (res * res) % MOD;
        if (b & 1) {
            return (res * a) % MOD;
        }
        return res;
    }

    ll nCr(ll n, ll r) {
        ll res = p[n];
        res = (res * exp(p[n - r], MOD - 2)) % MOD;
        res = (res * exp(p[r], MOD - 2)) % MOD;
        return res;
    }

    int countKSubsequencesWithMaxBeauty(string s, int k) {
        unordered_map<char, ll> f;

        for (char c : s) {
            f[c]++;
        }

        if (k > f.size()) {
            return 0;
        }

        priority_queue<ll> pq;

        for (const auto [character, freq] : f) {
            pq.push(freq);
        }

        p[0] = 1LL;

        for (int i = 1; i < MN; ++i) {
            p[i] = (p[i - 1] * i) % MOD;
        }

        ll ans = 1LL;

        while (k > 0) {
            ll num_way = pq.top();
            int cnt_num_of_freq = 0;
            while (!pq.empty() and pq.top() == num_way) {
                cnt_num_of_freq++;
                pq.pop();
            }
            if (k >= cnt_num_of_freq) {
                ans = (ans * exp(num_way, cnt_num_of_freq)) % MOD;
                k -= cnt_num_of_freq;
            }
            else {
                ans = (ans * ((nCr(cnt_num_of_freq, k) * exp(num_way, k)) % MOD)) % MOD;
                break;
            }
        }

        return (int) ans;
    }
};