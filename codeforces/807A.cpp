#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int n, a, b, prev = 100000, ok = 0, maybe = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		if (a > prev) maybe = 0;
		prev = a;
		if (a != b) ok = 1;
	}

	if (ok) printf("rated\n");
	else if (maybe) printf("maybe\n");
	else printf("unrated\n");

	return 0;
}