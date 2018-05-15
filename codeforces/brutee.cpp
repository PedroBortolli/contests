#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int n, ans = INT_MAX;
string stra = "zzzzzzzzzzzzz";

void go(int id, int arr[], int mn) {
	if (id == n) {
		map <int, int> mp;
		for (int i = 0; i < n; i++) {
			mp[arr[i]]++;
		}
		int ok = 1;
		for (int i = 1; i <= 8; i++) {
			if (mp[i] != 1) ok = 0;
		}
		if (ok) {
			if (mn <= ans) {
				ans = mn;
				string str;
				for (int i = 0; i < n; i++) {
					str += (arr[i]+'0');
					str += " ";
				}
				stra = str;
			}
		}
	}
	go(id+1, arr, mn);
	int ori = arr[id];
	for (int i = 1; i <= n; i++) {
		arr[id] = i; 
		go(id+1, arr, mn+1);
		arr[id] = ori;
	}
}

int v[11];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	int aux[8];
	for (int i = 0; i < n; i++) {
		aux[i] = v[i];
	}

	go(0, aux, 0);
	printf("%d\n", ans);
	cout << stra << endl;

	return 0;
}