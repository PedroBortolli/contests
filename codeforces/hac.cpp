#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int main() {
	int n,i,k, cnt = 0;
	ll ans = 0;
	vector <bool> v(1000005, 0);
	bool f = false;
	int temp = 25;
	ll ans1 = 0, gre = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		v[k] = true;
		if (k > 25) {
			if (!f) {
				f = true;
				ans1 = k-temp;
				temp=k;
			}
			gre++;
		}
	}

	if (!f) {
		cout << "0" << endl;
		return 0;
	}

	if (n == 25) {
		cnt = 0;
		i = 1;
		while (cnt != 25) {
			if (v[i]) {
				cnt++;
			}
			else {
				ans++;
			}
			i++;
		}
		cout << ans << endl;
	}
	else {
		i = temp+1;
		gre--;
		while (gre) {
			if (v[i]) {
				ans1 += i-temp;
				temp=i;
				gre--;
			}
			i++;
		}
		cout << ans1 << endl;
	}

	return 0;
}