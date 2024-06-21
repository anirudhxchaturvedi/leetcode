class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int zeroSum = 0;  // Sum of satisfied customers when not grumpy
        int maximum = 0;  // Maximum additional satisfied customers we can achieve
        int windowSum = 0;  // Current window sum of potentially satisfied customers

        // Calculate initial zeroSum and the initial windowSum for the first 'minutes' window
        for (int i = 0; i < grumpy.size(); i++) {
            if (grumpy[i] == 0) {
                zeroSum += customers[i];
            }
            if (i < minutes) {
                if (grumpy[i] == 1) {
                    windowSum += customers[i];
                }
            }
        }

        maximum = windowSum;  // Initialize maximum with the first windowSum

        // Slide the window across the array
        for (int i = minutes; i < grumpy.size(); i++) {
            if (grumpy[i] == 1) {
                windowSum += customers[i];
            }
            if (grumpy[i - minutes] == 1) {
                windowSum -= customers[i - minutes];
            }
            maximum = max(maximum, windowSum);
        }

        return zeroSum + maximum;
    }
};
