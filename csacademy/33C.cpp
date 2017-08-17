#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int ans = INT_MAX;
void go(int x, int steps) {
	if (x <= 1) {
		if (x <= 0) steps--;
		ans = min(steps, ans);
		return;
	}
	if (x%3 == 0) {
		go(x/3, steps+1);
		//go(x/3+1, steps+4);
		//go(x/3-1, steps+4);
	}
	else {
		if ((x+1)%3 == 0) {
			go(x+1, steps+1);
			go(x-2, steps+2);
		}
		else {
			go(x+2, steps+2);
			go(x-1, steps+1);
		}
	}
}

int main() {
	int x;
	scanf("%d", &x);
	go(x, 0);
	printf("%d\n", ans);
	return 0;
}

/*
5, 4, 3, 1

7, 6, 2, 3, 1
7, 8, 9, 3, 1

10, 9, 3, 1


14, 15, 5, 6, 2, 3, 1
14, 13, 12, 4, 3, 1


33, 11, 10, 9, 3, 1
33, 11, 12, 4, 3, 1
*/