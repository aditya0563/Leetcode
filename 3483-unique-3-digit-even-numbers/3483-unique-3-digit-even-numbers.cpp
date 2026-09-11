class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int counts[10] = {0};
        
        for (int digit : digits) {
            counts[digit]++;
        }
        
        int validCount = 0;
        
        for (int num = 100; num <= 998; num += 2) {
            int d1 = num / 100;        
            int d2 = (num / 10) % 10;  
            int d3 = num % 10;
            
            counts[d1]--;
            counts[d2]--;
            counts[d3]--;
            
            if (counts[d1] >= 0 && counts[d2] >= 0 && counts[d3] >= 0) {
                validCount++;
            }
            
            counts[d1]++;
            counts[d2]++;
            counts[d3]++;
        }
        
        return validCount;
    }
};