#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

vector <int> v[111];
int sum[111];
int main() {
	int n;
	scanf("%d", &n);
	int summ = (n*n*(n*n+1))/2;
	int need = summ/n;
	int b = 1, e = n*n;
	for (int l = 0; l < n*n; l++) {
		int i;
		if (l%2) i = b++;
		else i = e--;
		for (int j = 0; j < n; j++) {
			if (sum[j]+i <= need) {
				sum[j] += i;
				v[j].pb(i);
				break;
			}
		}	
	}

	for (int i = 0; i < n; i++) {
		for (auto a : v[i])
			printf("%d ", a);
		printf("\n");
	}

	return 0;
}