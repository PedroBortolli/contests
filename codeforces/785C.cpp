#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	ll n, m;
	scanf("%lld %lld", &n, &m);

	ll l = 0, r = n, mid = 0;

	while (l < r) {
		mid = (l+r)/2;
		cout << mid << endl;
		cout << l << " " << r << endl;
		if (mid*mid*mid - mid < n) r = mid;
		else if (mid*mid*mid == n) break;
		else l = mid;
	}

	printf("%lld\n", mid+1);
	return 0;
}