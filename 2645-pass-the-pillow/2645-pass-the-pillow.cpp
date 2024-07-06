class Solution {
public:
    int passThePillow(int n, int time) {
        int N = 2 * n - 2;
    int x = time % N;
    if (x < n) 
    {
        return 1 + x;
    } 
    else 
    {
        return 1 + (N - x);
    }
    }
};