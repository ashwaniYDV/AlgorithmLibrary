// https://www.scaler.com/problems/largest-number/

/*
Given a array A of non negative integers, arrange them such that they form the largest number.
Note: The result may be very large, so you need to return a string instead of an integer.


Input 1:
A = [3, 30, 34, 5, 9]
Output 1: 
"9534330"
 
Input 2:
A = [2, 3, 9, 0]
Output 2: 
"9320"
*/



/*
Sorting all numbers in descending order is the simplest solution that occurs to us. But this doesn’t work.
For example, 548 is greater than 60, but in the output, 60 comes before 548. 
As a second example, 98 is greater than 9, but 9 comes before 98 in the output.
The solution is to use any comparison based sorting algorithm. 
Thus, instead of using the default comparison, write a comparison function myCompare() and use it to sort numbers.
Given two numbers X and Y, how should myCompare() decide which number to put first – 
we compare two numbers XY (Y appended at the end of X) and YX (X appended at the end of Y).
If XY is larger, then, in the output, X should come before Y, else Y should come before X.
For example, let X and Y be 542 and 60. To compare X and Y, we compare 54260 and 60542. Since 60542 is greater than 54260, we put Y first.
*/


bool compareNum(string a, string b) {
    return a + b > b + a;
}
string Solution::largestNumber(const vector < int > & num) {
    string result;
    vector < string > str;
    for (int i = 0; i < num.size(); i++) {
        str.push_back(to_string(num[i]));
    }
    sort(str.begin(), str.end(), compareNum);
    for (int i = 0; i < str.size(); i++) {
        result += str[i];
    }
    int pos = 0;
    while (result[pos] == '0' && pos + 1 < result.size()) pos++;
    return result.substr(pos);

}
