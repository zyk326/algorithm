#include<iostream>
#include<vector>
#include<string.h>
#include<queue>

#define MaxSize 502

using namespace std;

int i, j, point, N, M;
struct city{
	int nums = 0;
	vector<int> neighbour;
}cities[MaxSize];
int ans[5002];
int line[5002];
int noded[502];

int BFS(int a, int b){
	queue<int> qi;
	int check[502];
	memset(check, 0, sizeof(check));
	qi.push(a);
	while(!qi.empty()){
		int buf = qi.front();
		qi.pop();
		for(int jj = 0; jj < cities[buf].nums; jj++){
			if(cities[buf].neighbour[jj] == b && noded[cities[buf].neighbour[jj]] == 0){
				return 1;	
			}
			if(check[cities[buf].neighbour[jj]] == 0 && noded[cities[buf].neighbour[jj]] == 0){
				check[cities[buf].neighbour[jj]] = 1; 
				qi.push(cities[buf].neighbour[jj]);
			}
		}
	}
	return 2;
}

int deal(int start){
	noded[start] = 1;
	if(cities[start].nums == 0 || cities[start].nums == 1){
		return 1;
	}
	for(int ii = 0; ii < cities[start].nums; ii++){
		for(int jj = 1; jj < cities[start].nums; jj++){
			return BFS(cities[start].neighbour[ii], cities[start].neighbour[jj]);
		}	
	}
}

int main(){
	cin >> N >> M;
	memset(noded, 0, sizeof(noded));
	for(i = 0; i < M; i++){
		cin >> j >> point;
		cities[j].neighbour.push_back(point);
		cities[j].nums++;
		cities[point].neighbour.push_back(j);
		cities[point].nums++;
	}	
	cin >> M;
	for(i = 0; i < M; i++){
		cin >> point;
		line[i] = point;
		ans[i] = deal(point);
	}	
	for(i = 0; i < M; i++){
		if(ans[i] == 1){
			cout << "City " << line[i] << " is lost." << endl;
		}else if(ans[i] == 2){
			cout << "Red Alert: " << "City " << line[i] << " is lost!" << endl;
		}
	}	
	if(i == N){
		cout << "Game Over.";
	}
	return 0;
}

