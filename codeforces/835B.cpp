#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char s[100005];
int mp[111];
int main() {
	int k, sum = 0;
	scanf("%d", &k);
	scanf(" %s", s);
	int n = strlen(s);
	for (int i = 0; i < n; i++) {
		mp[s[i]-'0']++;
		sum += (s[i]-'0');
	}

	int ans = 0;
	if (sum >= k) {
		printf("0\n");
		return 0;
	}
	else {
		while (sum < k) {
			for (int i = 0; i <= 8 && sum < k; i++) {
				while (mp[i]--) {
					sum += (9-i);
					ans++;
					if (sum >= k) break;
				}
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}