class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product=1;int zero=0;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            product*=nums[i];
            if(nums[i]==0)
            zero++;
        }
        if(zero<2){
        for(int j=0;j<nums.size();j++)
        {
            
            if(nums[j]!=0&&zero==0)
            ans.push_back(product/nums[j]);
            else if(nums[j]!=0&&zero==1)
            ans.push_back(0);
            else
            ans.push_back(product);
        }
        }
        else{
        for(int j=0;j<nums.size();j++)
        {
            
           ans.push_back(0);
        }
        }
        return ans;
    }
};