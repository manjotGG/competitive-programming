#include <iostream>
using namespace std;
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        auto solve = [&](vector<int>& Astart,
                         vector<int>& Adur,
                         vector<int>& Bstart,
                         vector<int>& Bdur) -> long long {

            int m = Bstart.size();

            vector<pair<int, int>> rides;
            rides.reserve(m);

            for (int i = 0; i < m; i++) {
                rides.push_back({Bstart[i], Bdur[i]});
            }

            sort(rides.begin(), rides.end());

            vector<int> starts(m);
            vector<long long> prefMinDur(m);
            vector<long long> suffMinFinish(m);

            for (int i = 0; i < m; i++) {
                starts[i] = rides[i].first;

                if (i == 0)
                    prefMinDur[i] = rides[i].second;
                else
                    prefMinDur[i] =
                        min(prefMinDur[i - 1], (long long)rides[i].second);
            }

            for (int i = m - 1; i >= 0; i--) {
                long long val =
                    (long long)rides[i].first + rides[i].second;

                if (i == m - 1)
                    suffMinFinish[i] = val;
                else
                    suffMinFinish[i] =
                        min(suffMinFinish[i + 1], val);
            }

            long long best = LLONG_MAX;

            for (int i = 0; i < (int)Astart.size(); i++) {
                long long finishA =
                    (long long)Astart[i] + Adur[i];

                int pos =
                    upper_bound(starts.begin(), starts.end(), finishA)
                    - starts.begin();

                long long cur = LLONG_MAX;

                // Ride B already open
                if (pos > 0) {
                    cur = min(cur,
                              finishA + prefMinDur[pos - 1]);
                }

                // Need to wait for Ride B to open
                if (pos < m) {
                    cur = min(cur,
                              suffMinFinish[pos]);
                }

                best = min(best, cur);
            }

            return best;
        };

        long long ans1 = solve(
            landStartTime,
            landDuration,
            waterStartTime,
            waterDuration
        );

        long long ans2 = solve(
            waterStartTime,
            waterDuration,
            landStartTime,
            landDuration
        );

        return (int)min(ans1, ans2);
    }
};