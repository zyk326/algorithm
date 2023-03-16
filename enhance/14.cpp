#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Node{
	int nodes;
	vector<int> besides;
}Nodes[201];
int i, j, point, N, path[2001], k, nums, nods[201];
int ans[20001];

int main(){
	cin >> nums >> j;
	for(i = 0; i < j; i++){
		cin >> point;
		Nodes[point].nodes++;
		cin >> N;
		Nodes[point].besides.push_back(N);
		Nodes[N].besides.push_back(point);
	}
	cin >> N;
	for(i = 0; i < N; i++){
		for(int mm = 1; mm <= nums; mm++){
			nods[mm] = 0;
		}
		cin >> point;
		for(j = 0; j < point; j++){
			cin >> path[j];		
		}
		ans[i] = 1;
		if(path[0] != path[point - 1]){
			ans[i] = 0;
			continue;
		}
		for(j = 0; j < point - 1; j++){
			if(nods[path[j]] == 1 || find(Nodes[path[j]].besides.begin(), Nodes[path[j]].besides.end(), path[j + 1]) == Nodes[path[j]].besides.end()){
				ans[i] = 0;
				break;
			}
			nods[path[j]] = 1;
		}
		for(k = 1; k <= nums; k++){
			if(nods[k] == 0){
				ans[i] = 0;
				break;
			}
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