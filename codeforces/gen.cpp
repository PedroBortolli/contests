#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
//
#define prin(a) if(debug) cout << #a << " = " << (a) << endl
#define separa() if(debug) cout << endl
#define fi first
#define se second
#define MOD 1000000007
#define N 100100
const double PI = acos(-1.0);
const double eps = 1e-9;
//
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	srand(time(NULL));
	int n, m, k;
	n = 500, m = 500, k = 500;
	printf("%d %d %d\n", n, m, k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x = rand()%2;
			printf("%d", x);
		}
		printf("\n");
	}	

	return 0;
}