#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int f[105], aux[105];
set <int> ans;
int main() {
	int n, m, x, y;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		f[x] = y;
	}
	for (int i = 1; i <= 100; i++) {
		int num = 0, cont = 1;
		for (int j = 1; j <= 100; j++) {
			aux[j] = cont;
			num++;
			if (num == i) {
				cont++;
				num = 0;
			}
		}
		int ok = 1;
		for (int j = 1; j <= 100; j++) {
			if (f[j] && f[j] != aux[j]) {
				ok = 0;
				break;
			}
		}
		if (ok) ans.insert(aux[n]);
	}
	if ((int)ans.size() > 1) printf("-1\n");
	else printf("%d\n", *ans.begin());
}