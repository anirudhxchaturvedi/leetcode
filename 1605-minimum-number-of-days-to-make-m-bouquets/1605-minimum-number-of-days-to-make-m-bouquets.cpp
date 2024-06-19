class Solution {
public:
    bool isokaydays(int mid,vector<int>& bloomDay, int m,int k)
    {
        int conseccount=0;int numofbouquet =0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=mid)
            conseccount++;
            else
            conseccount=0;

            if(conseccount==k)
            {
                numofbouquet++;
                conseccount=0;
            }
        }
        return (numofbouquet>=m);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if((long)m*k>n)
        return -1;
        int l=1;
        int r=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(isokaydays(mid,bloomDay,m,k)){
            ans=mid;
            r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};