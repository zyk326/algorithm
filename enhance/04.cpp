#include<iostream>

using namespace std;

int fa[10005];
int cnt[10005];
int n, m, x, y, i;

int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main(){
	//cout << "hello world" << endl;
	cin >> m;
	for(i = 0; i < 10005; i++){
		fa[i] = i;
		cnt[i] = 0;
	}
	while(m--){
		cin >> x >> y;
		int fax = find(x);
		int fay = find(y);
		if(fax - fay){
			fa[fax] = fay;
		}
		cnt[x]++;
		cnt[y]++;
	}
	int f = find(1);
	int flag = 1;
	if(cnt[1] % 2){
		flag = 0;
	}
	for(i = 1; i <= n; i++){
		if((cnt[i] && find(i) != f) || cnt[i] % 2){
			flag = 0;
			break;
		}
	}
	cout << flag << endl;
	return 0;
}
