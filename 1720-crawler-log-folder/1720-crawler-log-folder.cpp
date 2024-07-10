class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count=0;
        for(auto i : logs){
            if (i=="../")
            {
                if(count>0)
                count--;
            }
            else if(i=="./")
            continue;
            else{
            count++;
            }
        }
        return count;
    }
};