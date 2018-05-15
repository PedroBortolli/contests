#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[200005];
map <int, int> f;
int main() {
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		v[i] = x;
		if (f.find(x-1) != f.end()) f[x] = f[x-1]+1;
		else f[x] = 1;
	}

	int mx = 0, ed = 0;
	for (auto a : f) {
		if (a.second > mx) {
			mx = a.second;
			ed = a.first;
		}
	}

	printf("%d\n", mx);
	vector <int> ids;
	for (int i = n-1; i >= 0 && mx; i--) {
		if (v[i] == ed) {
			ids.pb(i);
			ed--;
			mx--;
		}
	}

	reverse(ids.begin(), ids.end());
	for (auto a : ids)
		printf("%d ", a+1);
	printf("\n");
	return 0;
}