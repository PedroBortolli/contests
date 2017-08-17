#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int f[222];
char s[100005];
int main() {
	scanf(" %s", s);
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		f[s[i]]++;
	}

	int ans = f['0'];
	for (int i = '1'; i <= '9'; i++) {
		if (f[i] != ans) {
			printf("0\n");
			return 0;
		}
	}

	printf("1\n");
	return 0;
}