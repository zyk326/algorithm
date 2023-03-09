#include<iostream>
#define MaxSize 202

using namespace std;

int i, j, k, point, N;
int M, K;
int relation[MaxSize][MaxSize];
int ans[MaxSize];

int deal(int peoO, int peoT){
	if(relation[peoO][peoT] == 0){
		return 2;
	}else if(relation[peoO][peoT] == 1){
		return 1;
	}else if(relation[peoO][peoT] == -1){
	//dp find friend
		for(int jj = 1; jj <= N; jj++){
			if(relation[peoO][jj] == 1){
				for(int kk = 1; kk <= N; kk++){
					if(relation[jj][peoT] == 1){
						//cout << peoO << " -- " << jj << " -- " << peoT << endl; 
						return 3;
					}
				}
			}
		}
	}
	return 4;
}

int main(){
	cin >> N >> M >> K;
	for(i = 0; i < M; i++){
		cin >> j >> k >> point;
		relation[j][k] = point;
		relation[k][j] = point;
	}
	for(i = 0; i < K; i++){
		cin >> j >> k;
		ans[i] = deal(j, k);
	}
	for(i = 0 ; i < K; i++){
		if(ans[i] == 1){
			cout << "No problem";
		}else if(ans[i] == 2){
			cout << "OK";
		}else if(ans[i] == 3){
			cout << "OK but...";	
		}else if(ans[i] == 4){
			cout << "No way";
		}
		cout << endl;
	}
	return 0;
}

