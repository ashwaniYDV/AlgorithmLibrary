#include <iostream>

using namespace std;

int main() {
    int size;
    string s;

    while(getline(cin, s)) {
        size = s.size();
        for (int i = 0; i < size; i++) {
            if(isalpha(s[i])) {
                if (islower(s[i])) {
                    //if (s[i] + 13 > 'z' || s[i] + 13 > 'Z')
                    if (s[i] + 13 > 'z') s[i] = s[i] + 13 - 26;
                    else s[i] = s[i] + 13;
                }

                if (isupper(s[i])) {
                    //if (s[i] + 13 > 'Z' || s[i] + 13 > 'Z')
                    if (s[i] + 13 > 'Z') s[i] = s[i] + 13 - 26;
                    else s[i] = s[i] + 13;
                }
            }

        }
        cout << s << endl;
    }


    return 0;
}