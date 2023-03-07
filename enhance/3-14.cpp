#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Node{
	int nodes;
	vector<int> besides;
}Nodes[2001];
int i, j, point, N, path[2001], k, nums, nods[2001];
int ans[200001];

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
		//cout << "now i is : " << i << endl;
		cin >> point;
		for(j = 0; j < point; j++){
			cin >> path[j];		
		}
		if(point != nums + 1){
			ans[i] = 0;
			continue;
		}
		ans[i] = 1;
		if(path[0] != path[point - 1]){
			//cout << i <<  " : " << "rear" << endl;
			ans[i] = 0;
			continue;
		}
		for(j = 0; j < point - 1; j++){
			//nods[path[j]] = 1;
			if(nods[path[j]] == 1 || find(Nodes[path[j]].besides.begin(), Nodes[path[j]].besides.end(), path[j + 1]) == Nodes[path[j]].besides.end()){
				//cout << i << " | " << nods[path[j]] << " out place is : " << path[j] << " -- " << path[j+ 1] << endl;
				//if(nods[path[j]] == 1) cout << " path loaded " << endl;
				ans[i] = 0;
				//nods[path[j]] = 1;
				break;
			}
			nods[path[j]] = 1;
			//path[j] = 0;
		}
		//point = 0;
		for(k = 1; k <= nums; k++){
			if(nods[k] == 0){
				ans[i] = 0;
				break;
			}
			//point++;
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
