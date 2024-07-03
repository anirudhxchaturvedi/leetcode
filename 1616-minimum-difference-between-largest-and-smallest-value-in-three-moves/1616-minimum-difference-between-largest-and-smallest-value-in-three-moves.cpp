class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4)
        return 0;
        
        sort(nums.begin(),nums.end());
           return min({
            nums[nums.size() - 4] - nums[0],
            nums[nums.size() - 1] - nums[3],
            nums[nums.size() - 3] - nums[1],
            nums[nums.size() - 2] - nums[2]
        });
    }
};