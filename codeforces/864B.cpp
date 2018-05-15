#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int n;
	char x;
	scanf("%d", &n);
	set <char> s;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		scanf(" %c", &x);
		if (x >= 'A' && x <= 'Z') {
			ans = max(ans, (int)s.size());
			s.clear();
		}
		else s.insert(x);
	}
	ans = max(ans, (int)s.size());
	printf("%d\n", ans);

	return 0;
}