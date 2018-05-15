#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int dp[3003][3003], n;
char v[3003][3003];
bool choice[3003][3003];

int go(int id, int col) {
	if (id == n-1) return v[id][col];
	if (dp[id][col] != -1) return -1;
	int a = go
}

int main() {
		

	return 0;
}