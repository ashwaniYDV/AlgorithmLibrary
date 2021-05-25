// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435c44/00000000007ec28e
// https://youtu.be/zUoOxH_XT6A

/*
Ham x ka use hi nhi krenge
Ham apni taraf se best possible answer generate krenge.
*/

const int N = 60;
int n, m;

int w,e;

double dp[60][60][60];
char best[60][60][60];

double go(int day, int rockCnt, int paperCnt) {
    if(day == 60) return 0;

    if(dp[day][rockCnt][paperCnt] != -1) return dp[day][rockCnt][paperCnt];

    int scissorCnt = day - rockCnt - paperCnt;

    // ye opponent ki different probabilities hai is day ke lie
    double probRock, probPaper, probScissor;

    // probability of opponent chosing rock or paper or scissor
    if(day == 0) {
        probRock = probPaper = probScissor = 1.0 / 3;
    } else {
        probRock = 1.0 * scissorCnt / day;
        probPaper = 1.0 * rockCnt / day;
        probScissor = 1.0 * paperCnt / day;
    }

    double res = 0, tmp = 0;
    
    // player choses rock
    tmp = probScissor * w + probRock * e + go(day+1, rockCnt+1, paperCnt);
    if(tmp > res){
        res = tmp;
        best[day][rockCnt][paperCnt] = 'R';
    }
    // player choses paper
    tmp = probRock * w + probPaper * e + go(day+1, rockCnt, paperCnt+1);
    if(tmp > res) {
        res = tmp;
        best[day][rockCnt][paperCnt] = 'P';
    }
    // player choses scissor
    tmp = probPaper * w + probScissor * e + go(day+1, rockCnt, paperCnt);
    if(tmp > res) {
        res = tmp;
        best[day][rockCnt][paperCnt] = 'S';
    }

    return dp[day][rockCnt][paperCnt] = res;
}

void solve(int testcase) {
    memset(dp, -1, sizeof dp);
    
    cin >> w >> e;
    
    go(0, 0, 0);
    
    int rock = 0, paper = 0;
    string res = "";
    f(day, 60) {
        // choose best
        char c = best[day][rock][paper];
        res += c;
        if(c == 'R') rock++;
        if(c == 'P') paper++;
    }

    kickstart(testcase, res);
}
 
signed main() {
    IOS
    int t = 1;
    cin >> t;
    int x; cin >> x;
    f(i, t) {
        solve(i+1);
    }
}
