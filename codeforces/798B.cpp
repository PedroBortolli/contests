#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

string s[55];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	int resf = INT_MAX, ans = 0, temp = 0;
	int ok = 1, okgeral = 1;
	for (int i = 0; i < n; i++) {
		ans = 0;
		ok = 0;
		okgeral = 0;
		for (int j = 0; j < n; j++) {
			if (j == i) continue;
			string lala = s[j];
			int len = lala.length();
			int temp = INT_MAX;
			if (s[j] == s[i]) {
				temp = 0;
				ok = 1;
			}
			for (int k = 1; k <= len; k++) {
				char aux = *(lala.begin());
				lala.erase(lala.begin());
				lala.pb(aux);
				if (lala == s[i]) {
					temp = min(temp, k);
					ok = 1;
				}
			}
			if (ok) okgeral++;
			ans += temp;
		}
		if (okgeral < n-1) continue;
		resf = min(resf, ans);
	}

	if (resf == INT_MAX or resf < -1) printf("-1\n");
	else printf("%d\n", resf);

	return 0;
}