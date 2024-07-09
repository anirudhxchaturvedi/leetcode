class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();

        vector<int> deliver(n);
        deliver[0] = customers[0][0] + customers[0][1];
        
        for(int i = 1; i < n; i++) {
            deliver[i] = max(deliver[i - 1] + customers[i][1], customers[i][0] + customers[i][1]);
        }

        double total_waiting_time = 0.0;
        for(int i = 0; i < n; i++) {
            total_waiting_time += deliver[i] - customers[i][0];
        }
        return total_waiting_time / n;
    }
};