#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Node{
	int nodes;
	vector<int> besides;
}Nodes[201];
int i, j, point, N, path[201], k;
int ans[20001];

int main(){
	cin >> i >> j;
	for(i = 0; i < j; i++){
		cin >> point;
		Nodes[point].nodes++;
		cin >> N;
		Nodes[point].besides.push_back(N);
		Nodes[N].besides.push_back(point);
	}
	cin >> N;
	for(i = 0; i < N; i++){
		cin >> point;
		for(j = 0; j < point; j++){
			cin >> path[j];		
		}
		ans[i] = 1;
		if(path[0] != path[point - 1]){
			ans[i] = 0;
			break;
		}
		for(j = 0; j < point - 1; j++){
			if(!path[j] || find(Nodes[path[j]].besides.begin(), Nodes[path[j]].besides.end(), path[j + 1]) == Nodes[path[j]].besides.end()){
				//cout << path[j] << " -- " << path[j+ 1] << endl;
				ans[i] = 0;
				break;
			}
			path[j] = 0;
		}
	}
	for(i = 0; i < N; i++){
		if(ans[i])
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
