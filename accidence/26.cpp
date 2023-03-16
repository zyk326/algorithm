#include<iostream>

using namespace std;

int N;
int nums[11];
int f, l;
int i;
int maxx, minn;

int main(){
    cin >> N;
    f = 0;
    l = 0;
    for(i = 0; i < N; i++){
        cin >> nums[i];
    }
    for(i = 1; i < N; i++){
        if(nums[i] > nums[f]){
            f = i;
        }
        else if(nums[i] < nums[l]){
            l = i;
        }
    }
    maxx = nums[f];
    minn = nums[l];
    int temp;

    temp = nums[0];
    nums[0] = minn;
    nums[l] = temp;

    if(nums[f] != maxx){
        f = l; 
    }

    temp = nums[N - 1];
    nums[N - 1] = maxx;
    nums[f] = temp;


    for(i = 0; i < N; i++){
        cout << nums[i] << " ";
    }

    return 0;
}