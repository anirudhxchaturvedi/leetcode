class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int maxprofit=0;
        sort(worker.begin(),worker.end());
        for (int j=0;j<worker.size();j++)
        {
            int p=0;
            for(int i=0;i<difficulty.size();i++)
            {
                if(worker[j]>=difficulty[i])
                {
                    p=max(p,profit[i]);
                }
            }
            maxprofit+=p;
        }
        return maxprofit;
    }
};