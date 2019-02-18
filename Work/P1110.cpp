#include<bits/stdc++.h>
const int maxn = 1000005;
const int INF = 0x3f3f3f3f;
int a[maxn], last[maxn];
int n, m;
std::multiset<int> all, gap;
int sort_gap = INF;

int read() {
	int ans = 0, s = 1;
	char ch = getchar();
	while(ch > '9' || ch < '0') {
		if(ch == '-') s = -1;
		ch = getchar();
 	}
 	while(ch >= '0' && ch <= '9') {
 		ans = ans * 10 + ch - '0'; ch = getchar();
 	}
 	return s * ans;
}
void update(int x) {
	std::multiset<int>::iterator it = all.lower_bound(x);
	sort_gap = std::min(sort_gap, abs(*it - x));
	--it;
	sort_gap = std::min(sort_gap, abs(x - *it));
	all.insert(x);
}
int main() {
	n = read(), m = read();
	all.insert(-500000005); all.insert(500000005);
	for(int i = 1; i <= n; i++) last[i] = a[i] = read();
	for(int i = 1; i < n; i++) {
		gap.insert(abs(a[i + 1] - a[i]));
	}
	for(int i = 1; i <= n; i++) update(a[i]);
	char opt[20];
	while(m--) {
		scanf("%s", opt);
		if(opt[0] == 'I') {
			// INSERT
			int id = read(), val = read();
			if(id + 1 <= n) {
				// abs(a[id + 1] - last[id]) erase
				gap.erase(gap.find(abs(a[id + 1] - last[id])));
				// abs(a[id + 1] - val) insert
				gap.insert(abs(a[id + 1] - val));
			}
			// abs(last[id] - val) insert
			gap.insert(abs(last[id] - val));
			last[id] = val;

			update(val);
		} else if(opt[4] == 'S') {
			// MIN_SORT_GAP
			printf("%d\n", sort_gap);
		} else if(opt[4] == 'G') {
			// MIN_GAP
			printf("%d\n", *gap.begin());
		}
	}
	return 0;
}
