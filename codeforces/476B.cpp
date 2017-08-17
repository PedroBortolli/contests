#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

char a[12];
char b[12];
int n, total = 0;
map <int, int> mp;
int go(int id, int sum) {
	if (id == n) {
		mp[sum]++;
		total++;
	}
	else { 
		if (b[id] == '+') go(id+1, sum+1);
		else if (b[id] == '-') go(id+1, sum-1);
		else if (b[id] == '?') {
			go(id+1, sum+1);
			go(id+1, sum-1);
		}
	}
}

int main() {
	scanf("%s %s", a, b);	
	n = strlen(a);

	int goal = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == '+') goal++;
		else goal--;
	}

	go(0, 0);
	
	double ans = (double)mp[goal]/(double)total;
	printf("%.11lf\n", ans);

	return 0;
}