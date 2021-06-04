// https://youtu.be/v069aWK21wA

/*
Problem:
How many n digit numbers can be formed when the digits are in non-decreasing order and each digit is from 0 to 9 (number can contain leading zeros).

Solution:
(n+r-1) C (r-1)

where:
n = no of digits in each such number
r = no of distinct digits that can be used (for 0 to 9, r = 10)
*/


/*
Example:
How many 5 digit numbers can be formed when the digits are in non-decreasing order and each digit is from 0 to 3 (number can contain leading zeros).
Some exapmples can be - 01233, 02333, 02233 and so on.

x0 + x1 + x2 + x3 = 5

For 01233
x0 = 1, x1 = 1, x2 = 1, x3 = 2
For 02233
x0 = 1, x1 = 0, x2 = 2, x3 = 2

n = 5
r = 4
Res = (5+4-1)C(4-1)
*/
