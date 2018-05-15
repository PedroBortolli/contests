#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int n, r, k, mx, mn;
	scanf("%d %d %d", &n, &r, &k);
	int red = r;
	int blue = n-r;
	if (k > blue) {
		mx = red+blue-(k-blue);
	}
	else mx = red + k;

	if (k > red) {
		mn = k-red;
	}
	else mn = red-k;
	printf("%d %d\n", mn, mx);	

	return 0;
}