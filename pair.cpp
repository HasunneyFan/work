#include<bits/stdc++.h>
using namespace std;

int n, logn;
int stmin[500005][23], stgcd[500005][23];
int l, r, mid;
int len, sum, ans[500005];

bool check(){//len >= mid？
	int logmid = log2(mid);
	for(int i = 1; i+(1<<logmid)-1 <= n; i++){
		if(min(stmin[i][logmid], stmin[i+mid-(1<<logmid)][logmid]) 
		== __gcd(stgcd[i][logmid], stgcd[i+mid-(1<<logmid)][logmid])) 
			return 1;
	}
	return 0;
}

int main(){
//	freopen("pair.in", "r", stdin);
//	freopen("pair.out", "w", stdout);
	cin >> n;
	logn = log2(n);
	for(int i = 1, in; i <= n; i++){
		cin >> in;
		stmin[i][0] = stgcd[i][0] = in;
	}
	for(int j = 1; j <= logn; j++){
		for(int i = 1; i+(1<<j)-1 <= n; i++){
			stmin[i][j] = min(stmin[i][j-1], stmin[i+(1<<(j-1))][j-1]);
			stgcd[i][j] = __gcd(stgcd[i][j-1], stgcd[i+(1<<(j-1))][j-1]);
		}
	}
	
	l = 1; r = n;
	while(l <= r){
		mid = (l+r) / 2;
		if(check()){
			len = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	
	if(len == 1){
		cout << n << " " << 0 << endl;
		for(int i = 1; i <= n; i++) cout << i << " ";
		return 0;
	}
	
	int loglen = log2(len);
	for(int i = 1; i+(1<<loglen)-1 <= n; i++){
		if(min(stmin[i][loglen], stmin[i+len-(1<<loglen)][loglen]) 
			== __gcd(stgcd[i][loglen], stgcd[i+len-(1<<loglen)][loglen])) 
			ans[++sum] = i;
	}
	cout << sum-1 << " " << len << endl;
	for(int i = 1; i <= sum; i++) cout << ans[i] << " ";
	
	return 0;
}
