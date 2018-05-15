#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[100005];
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	set <pii> s;
	for (int i = 1; i <= min(k, n-1); i++) {
		s.insert({v[i], -i});
	}
	int p = k+1, top = v[0];

	for (int i = 0; i < n; i++) {
		top = v[i];
		if (s.empty()) break;
		pii fi = *(s.begin());
		if (fi.first < top) {
			swap(v[i], v[-fi.second]);
			break;
		}
		if (i == n-1) break;
		s.erase(s.find({v[i+1], -(i+1)}));
		if (p <= n-1) {
			s.insert({v[p], -p});
			p++;
		}
	}

	for (int i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");
	return 0;
}