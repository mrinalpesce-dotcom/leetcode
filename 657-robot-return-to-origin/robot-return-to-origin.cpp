class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;   // start at origin
        
        for(char move : moves) {
            if(move == 'U') y++;      // go up
            else if(move == 'D') y--; // go down
            else if(move == 'R') x++; // go right
            else if(move == 'L') x--; // go left
        }
        
        // check if back to origin
        return (x == 0 && y == 0);
    }
};