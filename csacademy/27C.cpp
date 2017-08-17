#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

set <int> s[13], ok[13];
set <int> col[100005];
int cont[100005];
int mp[12][100005];
int main() {
	int n, m, l, r, x;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &l, &r, &x);
		if (s[x].find(l) != s[x].end()) mp[x][l] = max(r, mp[x][l]);
		else {
			mp[x][l] = r;
			s[x].insert(l);
		}
	}

	for (int i = 1; i <= 10; i++) {
		int prev = -1;
		for (auto a : s[i]) {
			int aux = a;
			if (aux < prev) {
				aux = prev+1;
				ok[i].insert(aux);
				mp[i][aux] = mp[i][a];
			}
			else ok[i].insert(aux);
			prev = mp[i][aux];
		}
		for (auto a : ok[i]) {
			l = a;
			r = mp[i][l];
			//printf("De %d ate %d eh cor %d\n", l, r, i);
			for (int j = l; j <= r; j++) {
				col[j].insert(i);
				cont[j]++;
			}
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= 100000; i++) {
		int ok = 0;
		if (cont[i] < n) ok = 1;
		ans = max(ans, (int)col[i].size()+ok);
	}

	printf("%d\n", ans);
	return 0;
}