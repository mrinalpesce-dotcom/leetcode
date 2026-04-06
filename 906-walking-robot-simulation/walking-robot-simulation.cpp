class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        
        // store obstacles
        set<pair<int,int>> obs;
        for(auto &o : obstacles)
            obs.insert({o[0], o[1]});
        
        // directions: N, E, S, W
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        int d = 0;      // facing north
        int x = 0, y = 0;
        int ans = 0;
        
        for(int cmd : commands){
            
            // turn right
            if(cmd == -1) d = (d + 1) % 4;
            
            // turn left
            else if(cmd == -2) d = (d + 3) % 4;
            
            // move forward
            else{
                for(int i = 0; i < cmd; i++){
                    int nx = x + dx[d];
                    int ny = y + dy[d];
                    
                    // stop if obstacle
                    if(obs.count({nx, ny})) break;
                    
                    x = nx;
                    y = ny;
                    ans = max(ans, x*x + y*y);
                }
            }
        }
        
        return ans;
    }
};