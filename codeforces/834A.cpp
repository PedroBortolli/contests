#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	char a, b;
	int n;
	scanf(" %c %c", &a, &b);
	scanf("%d", &n);
	n %= 4;
	char hold = a;
	for (int i = 0; i < n; i++) {
		if (a == '^') a = '>';
		else if (a == '>') a = 'v';
		else if (a == 'v') a = '<';
		else if (a == '<') a = '^';
	}

	string ans = "!";
	int ok = 0;
	if (a == b) {
		ans = "cw";
		ok = 1;
	}

	a = hold;
	for (int i = 0; i < n; i++) {
		if (a == '^') a = '<';
		else if (a == '<') a = 'v';
		else if (a == 'v') a = '>';
		else if (a == '>') a = '^';
	}

	if (a == b) {
		if (ok) printf("undefined\n");
		else printf("ccw\n");
		return 0;
	}
	cout << ans << "\n";
	return 0;
}