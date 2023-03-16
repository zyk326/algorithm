#include<iostream>
#include<iomanip>
#define MIN_ 1e-6
#define IS_ZERO(d) (abs(d) < MIN_) 

using namespace std;

int N;
int nums[1001];
int i, j;
int a1, a2, a3;
int maxs = -1, sum = 0;


int main(){
    cin >> N;
    for(i = 0; i < N; i++){
        cin >> nums[i];
        if(nums[i] % 3 == 0 && maxs < nums[i]){
            maxs = nums[i];
        }
        if((nums[i] - 1) % 3 == 0){
            a2++;
        }
        if((nums[i] - 2) % 3 == 0){
            a3++;
            sum += nums[i];
        }
    }
    if(maxs != -1){
        cout << maxs << " ";
    }else{
        cout << "NONE ";
    }
    if(a2 != 0){
        cout << a2 << " ";
    }else{
        cout << "NONE ";
    }
    if(sum != 0){
        cout << setprecision(1) << fixed << sum * 1.0 / a3;
    }else{
        cout << "NONE";
    }
    return 0;
}