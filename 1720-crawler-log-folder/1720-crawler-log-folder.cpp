class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count=0; string s="";
        for(auto i : logs){
            if (i=="../")
            {
                if(count>0)
                count--;
            }
            else if(i=="./")
            s="kuch nhi karna";
            else{
            count++;
            }
        }
        return count;
    }
};