#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

multiset <int> s;
pii v[200005];
int ans[200005];
int main() {
	int m, x;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		s.insert(-x);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		v[i] = mp(x, i);
	}

	sort(v, v+m);

	for (int i = 0; i < m; i++) {
		int x = *(s.begin());
		ans[v[i].second] = -x;
		s.erase(s.find(x));
	}

	for (int i = 0; i < m; i++)
		printf("%d ", ans[i]);

	printf("\n");
	return 0;
}