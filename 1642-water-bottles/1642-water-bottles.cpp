class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int answer=0;int emptyBottles=0;
        while (numBottles>0){
            answer+=numBottles;

            emptyBottles+=numBottles;
            numBottles=emptyBottles/numExchange;
            emptyBottles=emptyBottles%numExchange;

        }
        return answer;
    }
};