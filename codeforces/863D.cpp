#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int t[100005], l[100005], r[100005], b[105], mp[100005];
int main() {
	int n, q, m, x, y;
	scanf("%d %d %d", &n, &q, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		mp[i] = x;
	}

	for (int i = 1; i <= n; i++) {
		printf("mp[%d] = %d\n", i, mp[i]);
	}
	printf("\n\n\n");

	for (int i = 1; i <= q; i++) {
		scanf("%d %d %d", &t[i], &l[i], &r[i]);
	}

	for (int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
	}

	for (int i = 1; i <= q; i++) {
		int L = l[i], R = r[i], T = t[i];
		map <int, int> dup;
		for (int j = 1; j <= m; j++) {
			if (b[j] >= L && b[j] <= R) {
				if (T == 1) {
					if (b[j]-1 >= L) dup[b[j]] = mp[b[j]-1];
					else dup[b[j]] = mp[R];
					printf("Agora dup[%d] = %d\n", b[j], dup[b[j]]);
				}
				else {
					int pos = b[j];
					if (pos > (L+R)/2) {
						dup[b[j]] = mp[L+(R-pos)];
						//mp[b[j]] = L+(R-pos);
					}
					else {
						L = 3 R = 6    (R+L)/2 = 4
						pos = 3
						dup[3] = mp[6]

						pos = 4
						dup[4] = mp[5]

						dup[b[j]] = mp[R-(pos-L)];
						//mp[b[j]] = R-(pos-L);
					}
				}
			}
		}

		for (int j = 1; j <= m; j++) {
			if (dup[b[j]]) mp[b[j]] = dup[b[j]];
		}
		printf("\n\nNovas posicoes:\n");
		for (int j = 1; j <= n; j++) {
			printf("Mp[%d] = %d\n", j, mp[j]);
		}
	}

	for (int i = 1; i <= m; i++)
		printf("%d ", mp[b[i]]);
	printf("\n");
	return 0;
}

/*

1 2 3 4 5 6

3 2 1 4 5 6

3 2 6 5 4 1

1 3 2 6 5 4

*/