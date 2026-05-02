class Solution {
public:
    bool isGood(int num) {
        bool changed = false;
        
        while (num > 0) {
            int d = num % 10;
            
            // invalid digits
            if (d == 3 || d == 4 || d == 7) 
                return false;
            
            // digits that change after rotation
            if (d == 2 || d == 5 || d == 6 || d == 9)
                changed = true;
            
            num /= 10;
        }
        
        return changed; // must change to be GOOD
    }
    
    int rotatedDigits(int n) {
        int count = 0;
        
        for (int i = 1; i <= n; i++) {
            if (isGood(i))
                count++;
        }
        
        return count;
    }
};