#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[100005];
set <int> s;
set <int>::iterator it;
int main() {
	int n, u;
	scanf("%d %d", &n, &u);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		s.insert(v[i]);
	}

	double mx = -10000000000000000000.0;
	int ok = 0;
	for (int i = 0; i < n-2; i++) {
		int a = v[i];
		int b = v[i+1];
		int find = a+u;
		it = s.upper_bound(find);
		it--;
		if (it == s.begin() or it == s.end()) continue;
		int c = *it;
		//printf("%d %d %d\n", a, b, c);
		if (c == a or c == b or c-a > u) continue;
		double aux = (c-b)/(double)(c-a);
		ok = 1;
		mx = max(mx, aux);
	}

	if (!ok) printf("-1\n");
	else printf("%.15lf\n", mx);

	return 0;
}