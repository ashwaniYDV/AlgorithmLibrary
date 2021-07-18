// https://practice.geeksforgeeks.org/problems/multiply-two-strings/1
// https://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/

/*
Input:
s1 = "33"
s2 = "2"
Output:
"66"

Input:
s1 = "11"
s2 = "-23"
Output:
"-253"
*/


/*
The idea is based on school mathematics. 
*/

class Solution {
  public:
  
    string multiplyStrings(string s1, string s2) {
        if (s1 == "0" || s2 == "0") return "0";

        string sign = "";
        if (s1[0] == '-') {
            sign = "-";
            s1 = s1.substr(1);
        }

        if (s2[0] == '-') {
            sign = (sign == "-" ? "" : "-");
            s2 = s2.substr(1);
        }

        int n1 = s1.size(), n2 = s2.size();

        vector < int > res(n1 + n2, 0);

        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        for (int j = 0; j < n2; j++) {
            for (int i = 0; i < n1; i++) {
                int total = (s1[i] - '0') * (s2[j] - '0');
                res[i + j] += total;
                res[i + j + 1] += res[i + j] / 10;
                res[i + j] %= 10;
            }
        }

        reverse(res.begin(), res.end());

        string ans = "";
        int i = 0;
        while (res[i] == 0) {
            i++;
        }
        for (; i < res.size(); i++) {
            ans += to_string(res[i]);
        }

        return (sign + ans);
    }

};






class Solution{
  public:
  
    string multiplyStrings(string s1, string s2) {
        if (s1 == "0" || s2 == "0") return "0";

        string sign = "";
        if (s1[0] == '-') {
            sign = "-";
            s1 = s1.substr(1);
        }

        if (s2[0] == '-') {
            sign = (sign == "-" ? "" : "-");
            s2 = s2.substr(1);
        }

        int n1 = s1.size(), n2 = s2.size();

        vector < int > res(n1 + n2, 0);

        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                int total = (s1[i] - '0') * (s2[j] - '0');
                res[i + j] += total;
                res[i + j + 1] += res[i + j] / 10;
                res[i + j] %= 10;
            }
        }

        reverse(res.begin(), res.end());

        string ans = "";
        int i = 0;
        while (res[i] == 0) {
            i++;
        }
        for (; i < res.size(); i++) {
            ans += to_string(res[i]);
        }

        return (sign + ans);
    }
};
