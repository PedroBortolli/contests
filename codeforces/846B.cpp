#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[47];
int main() {
	int n, k, m, sum = 0;
	scanf("%d %d %d", &n, &k, &m);
	for (int i = 0; i < k; i++) {
		scanf("%d", &v[i]);
		sum += v[i];
	}
	sort(v, v+k);

	int lim = min(n, m/sum);
	int ans = 0;
	for (int i = 0; i <= lim; i++) {
		int rem = m;
		int cont = 0;
		rem -= (i*sum);
		cont += (i*(k+1));
		for (int j = 0; j < k; j++) {
			for (int l = 0; l < n-i; l++) {
				if (rem-v[j] >= 0) {
					cont++;
					rem -= v[j];
				}
			}
		}
		ans = max(ans, cont);
	}

	printf("%d\n", ans);
	return 0;
}