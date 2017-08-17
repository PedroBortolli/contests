#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

ll v[100005], a[100005], b[100005];
int main() {
	ll n;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &v[i]);
	}

	ll k = 0;
	if (n%2) {
		k = 0;
		for (int i = 0; i < n-1; i += 2) {
			a[k++] = v[i]+v[i+1];
		}
		k = 0;
		for (int i = 1; i < n; i += 2) {
			b[k++] = v[i]+v[i+1];
		}
	}

	else {
		k = 0;
		for (int i = 0; i < n; i += 2) {
			a[k++] = v[i]+v[i+1];
		}
		k = 0;
		for (int i = 1; i < n-1; i += 2) {
			b[k++] = v[i]+v[i+1];
		}
	}


	ll mxfar = -10000000000000005;
	ll mxhere = 0;
	ll ans;
	if (n%2) {
		for (int i = 0; i < n/2; i++) {
			mxhere = max(mxhere+a[i], a[i]);
			mxfar = max(mxhere, mxfar);
		}
		ans = mxfar;
		mxfar = -10000000000000005;
		mxhere = 0;
		for (int i = 0; i < n/2; i++) {
			mxhere = max(mxhere+b[i], b[i]);
			mxfar = max(mxhere, mxfar);
		}
		ans = max(ans, mxfar);
		printf("%lld\n", ans);
	}
	else {
		for (int i = 0; i < n/2; i++) {
			mxhere = max(mxhere+a[i], a[i]);
			mxfar = max(mxhere, mxfar);
		}
		ans = mxfar;
		mxfar = -10000000000000005;
		mxhere = 0;
		for (int i = 0; i < n/2-1; i++) {
			mxhere = max(mxhere+b[i], b[i]);
			mxfar = max(mxhere, mxfar);
		}
		ans = max(ans, mxfar);
		printf("%lld\n", ans);
	}

	return 0;
}