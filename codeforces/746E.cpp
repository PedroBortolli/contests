#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

set <int> odd, even;
map <int, int> mp;
int v[200005];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	m = min(m, 1000000);

	for (int i = 1; i <= m; i++) {
		if (i%2) odd.insert(i);
		else even.insert(i);
	}

	int oddcont = 0, evencont = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		mp[v[i]]++;
		if (v[i]%2) {
			oddcont++;
			if (odd.find(v[i]) != odd.end())
				odd.erase(v[i]);
		}
		else {
			evencont++;
			if (even.find(v[i]) != even.end())
				even.erase(v[i]);
		}
	}

	/*for (auto a : odd)
		printf("%d ", a);
	printf("\n");
	for (auto a : even)
		printf("%d ", a);
	printf("\n");*/

	int pair = 0;
	int need = abs(oddcont-evencont)/2;
	if (oddcont > evencont) pair = 1;
	else if (evencont > oddcont) pair = 2;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (v[i]%2) {
			if (mp[v[i]] == 1) continue;
			mp[v[i]]--;
			ans++;
			if (need == 0 or pair == 2) {
				auto it = odd.begin();
				if (it == odd.end()) {
					printf("-1\n");
					return 0;
				}
				v[i] = *it;
				odd.erase(it);
			}
			else {
				need--;
				auto it = even.begin();
				if (it == even.end()) {
					printf("-1\n");
					return 0;
				}
				v[i] = *it;
				even.erase(it);
			}
		}
		else {
			if (mp[v[i]] == 1) continue;
			mp[v[i]]--;
			ans++;
			if (need == 0 or pair == 1) {
				auto it = even.begin();
				if (it == even.end()) {
					printf("-1\n");
					return 0;
				}
				v[i] = *it;
				even.erase(it);
			}
			else {
				need--;
				auto it = odd.begin();
				if (it == odd.end()) {
					printf("-1\n");
					return 0;
				}
				v[i] = *it;
				odd.erase(it);
			}
		}
	}

	for (int i = 0; i < n && need > 0; i++) {
		if (v[i]%2) {
			if (pair == 2) continue;
			ans++;
			need--;
			auto it = even.begin();
			if (it == even.end()) {
				printf("-1\n");
				return 0;
			}
			v[i] = *it;
			even.erase(it);
		}
		else {
			if (pair == 1) continue;
			ans++;
			need--;
			auto it = odd.begin();
			if (it == odd.end()) {
				printf("-1\n");
				return 0;
			}
			v[i] = *it;
			odd.erase(it);
		}
	}

	printf("%d\n", ans);
	for (int i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");
	return 0;
}