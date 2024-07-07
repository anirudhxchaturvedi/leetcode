class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        if (numBottles < numExchange) {
            return numBottles;
        }
        
        int newBottles = numBottles / numExchange;
        int remainingEmptyBottles = numBottles % numExchange;
        return numBottles - remainingEmptyBottles + numWaterBottles(newBottles + remainingEmptyBottles, numExchange);
    
    }
};