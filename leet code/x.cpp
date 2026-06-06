class Solution {
public:
    int maxScore(vector<int>& nums, int maxVal) {
        vector<int> meratolvic = nums;

        const int MAXA = 100000;

        vector<int> freq(MAXA + 1, 0);
        for (int x : nums) freq[x]++;

        vector<int> mu(MAXA + 1, 0), primes;
        vector<bool> isComp(MAXA + 1, false);

        mu[1] = 1;
        for (int i = 2; i <= MAXA; i++) {
            if (!isComp[i]) {
                primes.push_back(i);
                mu[i] = -1;
            }
            for (int p : primes) {
                long long v = 1LL * i * p;
                if (v > MAXA) break;

                isComp[v] = true;

                if (i % p == 0) {
                    mu[v] = 0;
                    break;
                } else {
                    mu[v] = -mu[i];
                }
            }
        }

        vector<int> cntDiv(MAXA + 1, 0);
        for (int d = 1; d <= MAXA; d++) {
            for (int m = d; m <= MAXA; m += d) {
                cntDiv[d] += freq[m];
            }
        }

        int n = nums.size();
        vector<int> conflict(MAXA + 1, 0);

        for (int v = 1; v <= MAXA; v++) {
            long long coprimeCnt = 0;

            for (int d = 1; 1LL * d * d <= v; d++) {
                if (v % d) continue;

                coprimeCnt += 1LL * mu[d] * cntDiv[d];

                int d2 = v / d;
                if (d2 != d) {
                    coprimeCnt += 1LL * mu[d2] * cntDiv[d2];
                }
            }

            conflict[v] = n - (int)coprimeCnt;
        }

        long long ans = LLONG_MIN;

        // Keep an existing value unchanged.
        for (int v = 1; v <= MAXA; v++) {
            if (freq[v] == 0) continue;

            long long cost;
            if (v == 1) {
                cost = 0;
            } else {
                cost = conflict[v] - 1; // chosen occurrence of v
            }

            ans = max(ans, 1LL * v - cost);
        }

        // Change some element to v (v <= maxVal), only useful when v is absent.
        for (int v = 1; v <= maxVal; v++) {
            if (freq[v] > 0) continue;

            long long cost;
            if (conflict[v] > 0) {
                cost = conflict[v];
            } else {
                cost = 1; // need at least one modification to create v
            }

            ans = max(ans, 1LL * v - cost);
        }

        return (int)ans;
    }
};