#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[200005], mp[200005];
int main() {
	int n, cont = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		mp[v[i]]++;
	}

	set <int> s;
	for (int i = 1; i <= n; i++) {
		if (!mp[i]) {
			s.insert(i);
			cont++;
		}
	}

	int ans = 0, first = *(s.begin());
	if ((int)s.size() == 0) goto here;


	for (int i = 0; i < n; i++) {
		if (mp[v[i]] > 1) {
			if (first < v[i]) {
				mp[v[i]]--;
				v[i] = first;
				mp[v[i]] = 1;
				ans++;
				s.erase(s.find(first));
				if (!s.empty()) first = *s.begin();
				else break;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!mp[i]) s.insert(-i);
	}

	if ((int)s.size() == 0) goto here;
	first = - *s.begin();

	for (int i = n-1; i >= 0; i--) {
		if (mp[v[i]] <= 1) continue;

		ans++;
		mp[v[i]]--;
		v[i] = first;
		mp[v[i]] = 1;
		s.erase(s.find(-first));
		if (!s.empty()) first = - *s.begin();
		else break;
		
	}

	here:;

	printf("%d\n", cont);
	for (int i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");
	return 0;
}