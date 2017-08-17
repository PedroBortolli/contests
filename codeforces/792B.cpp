#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int v[105];
vector <int> a;
vector <int>::iterator it;
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		a.pb(i);

	for (int i = 0; i < k; i++) {
		scanf("%d", &v[i]);
	}

	//0 1 2 3 4 5 6

	int lead = 1;

	for (int i = 0; i < k; i++) {
		v[i] %= (n-i);
		for (it = a.begin(); it != a.end(); ++it) {
			if (*it == lead) break;
		}
		while (v[i]--) {
			it++;
			if (it == a.end()) it = a.begin();
		}
		printf("%d ", *it);
		if (i == k-1) break;
		vector <int>::iterator aux = it;
		aux++;
		if (aux == a.end()) aux = a.begin();
		lead = *aux;
		//printf("Lead agora = %d\n", lead);
		a.erase(it);
	}

	printf("\n");
	return 0;
}