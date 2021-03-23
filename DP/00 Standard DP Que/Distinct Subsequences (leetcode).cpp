
// TLE solution
class Solution {
public:
    struct node {
        int index;
        int size;
    };
    int numDistinct(string s, string t) {
        int n = s.size();

        queue<node> q;
        for(int i = 0; i < n; i++) {
            if(s[i] == t[0]) {
                q.push({i, 1});
            }
        }

        int cnt = 0;
        while(!q.empty()) {
            node x = q.front();
            q.pop();

            int index = x.index;
            int size = x.size;

            if(size == t.size()) {
                cnt++;
            }

            for(int i = index + 1; i < n; i++) {
                if(s[i] == t[size]) {
                    q.push({i, size + 1});
                }
            }
        }

        return cnt;
    }
};
