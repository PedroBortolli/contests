#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[111], has[111];
int main() {
	int n, w;
	scanf("%d %d", &n, &w);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	for (int i = 0; i < n; i++) {
		has[i] = v[i]/2 + v[i]%2;
		w -= has[i];
	}

	if (w < 0) {
		printf("-1\n");
		return 0;
	}

	for (int k = 0; k < 2*n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (v[i] > v[j] && has[i] < has[j]) {
					w -= (has[j]-has[i]);
					has[i] = has[j];
				}
			}
		}
	}

	if (w < 0) {
		printf("-1\n");
		return 0;
	}

	int id;
	while (w) {
		id = -1;
		for (int i = 0; i < n && w; i++) {
			for (int j = 0; j < n && w; j++) {
				if (v[i] > v[j] && v[i] != has[i]) {
					id = i;
				}
			}
		}
		if (id == -1 && w > 0) {
			printf("-1\n");
			return 0;
		}
		int aux = min(w, v[id]-has[id]);
		has[id] += min(w, v[id]-has[id]);
		w -= aux;
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", has[i]);
	}
	printf("\n");
	return 0;
}