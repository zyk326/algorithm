#include<iostream>
#include<queue>

#define maxSize 11

using namespace std;

int i, j, point1, point2, nodes, routes;
int map[maxSize][maxSize];

void findPathDFS(int start, int way[]){
	int k = 0;
	way[start] = 1;
	for(k = 0; k < nodes; k++){
		if(way[k] == 0 && map[start][k] == 1){
			cout << k << " "; 
			findPathDFS(k, way);
		}
	}
}

void findPathBFS(int start, int way[]){
	queue<int> qi;
	qi.push(start);
	way[start] = 1;
	int buf;
	while(!qi.empty()){
		buf = qi.front();
		qi.pop();
		for(int k = 0; k < nodes; k++){
			if(way[k] == 0 && map[buf][k] == 1){
				cout << k << " "; 
				qi.push(k);
				way[k] = 1;
			}
		}
	}
	
}

int main(){
	cin >> nodes >> routes;
	for(i = 0; i < routes; i++){
		cin >> point1 >> point2;
		map[point1][point2] = 1;
		map[point2][point1] = 1;
	}
       //for(i = 0; i < nodes; i++){
	//	for(j = 0; j < nodes; j++){
		//	cout << map[i][j] << " ";
		//}
		//cout << endl;
	//}
	int way1[maxSize];
	memset(way1, 0, sizeof(way1));
	for(i = 0; i < nodes; i++){
		if(way1[i] == 0){
			cout << "{ " << i << " ";
			findPathDFS(i, way1);
			cout << "}" << endl;
		}	
	}
	int way2[maxSize];
	memset(way2, 0, sizeof(way2));
	for(i = 0; i < nodes; i++){
		if(way2[i] == 0){
			cout << "{ " << i << " ";
			findPathBFS(i, way2);
			cout << "}" << endl;
		}
	}
	return 0;
}

