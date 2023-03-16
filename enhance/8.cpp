#include<iostream>

using namespace std;

int N;
int point;
int i, j;
int sizee = 0;
int roude[100001];

int main(){
    cin >> N;
    for(i = 0; i < N; i++){
        cin >> point;
        if(sizee == 0 || roude[sizee - 1] < point){
            roude[sizee++] = point;
        }else{
            int l = 0;
            int r = sizee - 1;
            int mid;
            while(l < r){
                mid = (l + r) / 2;
                if(roude[mid] > point){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
            roude[l] = point;
        }
    }
    cout << sizee << endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// int main(){
// 	int n;
// 	int num[100001];
// 	int len=0; 
// 	int k;
// 	cin >> n;
// 	while(n--) {
// 		cin >> k;
// 		if(len==0||num[len-1]<k){  //若刚开始暂无轨道或者没有轨道的最后一个数大于当前的数，另开轨道
// 			num[len++]=k;
// 		}
// 		else{ //若存在轨道最后一个数大于当前数，利用二分法去最优轨道（轨道最后一个数与当前数的差值最小）
// 			int l=0;
// 			int r=len-1;
// 			int mid;
// 			while(l<r){
// 				mid=(l+r)/2;
// 				if(num[mid]>k) r=mid-1;
// 				else l=mid+1;
// 			}
// 			num[l]=k;
// 		}
// 	}
//     cout << len << endl;
// 	return 0;
// } 
