#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

vector <int> ans;
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	if (k == 1) {
		printf("%d\n", n);
		return 0;
	}

	int cont = 0;
	while (n > 0 && cont < k-1) {
		for (int i = 2; i <= n; i++) {
			if (n%i == 0) {
				ans.pb(i);
				cont++;
				n /= i;
				break;
			}
		}
	}

	if (cont != k-1) printf("-1\n");
	else {
		printf("%d ", n);
		for (auto a : ans)
			printf("%d ", a);
		printf("\n");
	}

	return 0;
}