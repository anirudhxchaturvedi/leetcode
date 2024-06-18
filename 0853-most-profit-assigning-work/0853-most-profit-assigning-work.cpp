class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>vp;
        int n=difficulty.size();
        int m=worker.size();
        for(int i=0;i<n;i++)
        {
            vp.push_back({difficulty[i],profit[i]});
        }
        sort(vp.begin(),vp.end());
        sort(worker.begin(),worker.end());
        int profsum=0,maxprofit=0,j=0;
        for(int i=0;i<m;i++)
        {
            while(j<m&&vp[j].first<=worker[i])
            {
                maxprofit=max(maxprofit,vp[j].second);
                j++;
            }
            profsum+=maxprofit;
        }
        return profsum;
    }
};