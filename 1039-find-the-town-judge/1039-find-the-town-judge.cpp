class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
       if (n == 1 && trust.empty()) return 1;

        vector<int> trustCount(n + 1, 0);
        vector<int> trustedBy(n + 1, 0);

        for (const auto& t : trust) {
            if (t.size() != 2) continue; // Skip invalid trust entries
            int a = t[0];
            int b = t[1];
            trustCount[b]++;
            trustedBy[a]++;
        }

        for (int i = 1; i <= n; ++i) {
            if (trustCount[i] == n - 1 && trustedBy[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};