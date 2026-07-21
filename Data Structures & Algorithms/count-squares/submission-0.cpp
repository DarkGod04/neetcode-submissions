class CountSquares {
public:
    unordered_map<int, unordered_map<int,int>> cnt;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        cnt[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int ans = 0;

        for(auto &[ny, freq] : cnt[x]) {

            if(ny == y)
                continue;

            int d = ny - y;

            ans += freq *
                   cnt[x+d][y] *
                   cnt[x+d][ny];

            ans += freq *
                   cnt[x-d][y] *
                   cnt[x-d][ny];
        }

        return ans;
    }
};
