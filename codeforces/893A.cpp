#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int n, s = 3, x, ok = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x == s) ok = 0;
		if (x == 1 && s == 2) s = 3;
		else if (x == 1 && s == 3) s = 2;
		else if (x == 2 && s == 1) s = 3;
		else if (x == 2 && s == 3) s = 1;
		else if (x == 3 && s == 1) s = 2;
		else if (x == 3 && s == 2) s = 1; 
	}

	if (ok) printf("YES\n");
	else printf("NO\n");
	return 0;
}