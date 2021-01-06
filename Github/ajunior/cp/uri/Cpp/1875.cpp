#include <iostream>

using namespace std;

int main() {
    int c, p, r_M = 0, g_M = 0, b_M = 0, r_S = 0, g_S = 0, b_S = 0;
    char m, s;

    cin >> c;

    for (int i = 0; i < c; ++i) {
        cin >> p;
        for (int j = 0; j < p; ++j) {
            cin >> m >> s;

            if (m == 'R') r_M++;
            else if (m == 'G') g_M++;
            else b_M++;

            if (s == 'R') r_S++;
            else if (s == 'G') g_S++;
            else b_S++;
        }

        if ( (r_M == g_M && g_M == b_M) && (r_S == g_S && g_S == b_S) ) cout << "trempate\n";
        else if ( (r_M == g_M && g_M > b_M) || (g_M == b_M && b_M > r_M) || (b_M == r_M && r_M > g_M) ) {
            if ( (r_S == g_S && g_S > b_S) || (g_S == b_S && b_S > r_S) || (b_S == r_S && r_S > g_S) )
                cout << "empate\n";
        }
        else if (r_M > g_M && r_M > b_M) cout << "red\n";
        else if (g_M > b_M && g_M > r_M) cout << "green\n";
        else if (b_M > r_M && r_M > g_M) cout << "blue\n";

        r_M = g_M = b_M = r_S = g_S = b_S = 0;

    }
    return EXIT_SUCCESS;
}