class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count=0;
        for (int i=0;i<details.size();i++){
            int tens = details[i][11] - '0';  
            int units = details[i][12] - '0'; 
            int value = tens * 10 + units;             
            if(value>60)
            count++;
        }
        return count;
    }
};