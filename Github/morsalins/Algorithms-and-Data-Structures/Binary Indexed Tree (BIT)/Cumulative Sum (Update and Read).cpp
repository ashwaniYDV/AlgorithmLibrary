#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

#define MAX 2000

int arr[] = { 0, 1, 0, 2, 1, 1, 3, 0, 4, 2, 5, 2, 2, 3, 1, 0, 2 };
int BIT[MAX];

void init(int);
void update(int, int, int);
long int read(int);

int main()
{
	int n = 17;

	init(n);

	long int sum = read(14);
	cout << sum << endl;

	return 0;
}

void init(int n)
{
	for (int i = 1; i <= n; i++) {
		update(i, n, arr[i]);
		//1st update the whole array from index 1 to n. n = array size
	}
	return;
}

void update(int idx, int len, int value)
{
	while (idx <= len) {
		BIT[idx] += value;
		idx += (idx & -idx);
	}
	return;
}

long int read(int idx)
{
	long int sum = 0;

	while (idx > 0) {
		sum += BIT[idx];
		idx -= (idx & -idx);
	}
	return sum;
}