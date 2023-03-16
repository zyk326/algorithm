#include<iostream>
#include<algorithm>

using namespace std;

int N;
struct Num{
    string nn;
    int times = 0;
    bool operator <(const Num &a)const{
        if(times > a.times){
            return true;
        }else{
            return false;
        }
    }
};
Num nums[10];
int i, j;

int main(){
    cin >> N;
    string buf;
    int len;
    for(i = 0; i < N; i++){
        cin >> buf;
        len = buf.length();
        int point = 0;
        while(buf[point] != '\0'){
            nums[buf[point] - '0'].nn = buf.substr(point, 1);
            nums[buf[point] - '0'].times++;
            point++;
        }
    }
    sort(nums, nums + 10);
    // for(i = 0; i < 10; i++){
    //     cout << nums[i].nn << "   " << nums[i].times << endl;
    // }
    int max = nums[0].times;
    cout << max << ": ";
    for(i = 0; i < 10; i++){
        if(nums[i].times == max){
            cout << nums[i].nn;
        }else{
            break;
        }
        if(nums[i + 1].times == max){
            cout << " ";          
        }
    }
    return 0;
}