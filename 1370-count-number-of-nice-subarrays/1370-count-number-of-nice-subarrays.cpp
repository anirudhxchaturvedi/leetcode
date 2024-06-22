class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
     int n=nums.size(); int ans=0,prefixsum=0;
     unordered_map<int,int> frequency;//frequency of prefix sum
     frequency[0]=1;
     for(int i=0;i<n;i++)
     {
        prefixsum+= (nums[i]%2==1)? 1 : 0;
        ans+=frequency[prefixsum-k];
        frequency[prefixsum]++;
     }   
     return ans;
    }
};