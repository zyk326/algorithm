#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

int A, N;
int i, j, k;
string numb;
string ans = "";

string strSum(string befSum, string addNum){
    //addNum .length greater than befSum .length
    reverse(befSum.begin(), befSum.end());
    int point = 0;
    int len = befSum.length();
    int carry = 0;//jin wei
    while(point < len){
        addNum[point] = addNum[point] - '0' + befSum[point] + carry;
        if((addNum[point] - '0') / 10 != 0){
            carry = 1;
            addNum[point] -= 10;
        }else{
            carry = 0;
        }
        point++;
    }
    if(carry == 1){
        addNum[point] += 1;
        if(addNum[point] - '0' >= 10){
            addNum[point] = 0;
            addNum += "1";
        }
    }
    reverse(addNum.begin(), addNum.end());
    return addNum;
}

string createNum(int ii){
    string aa = "";
    while(ii > 0){
        aa += to_string(A);
        ii--;
    }
    return aa;
}

int main(){
    cin >> A >> N;
    /* way 1   :  16/20
    for(i = 1; i <= N; i++){
        numb = createNum(i);
        ans = strSum(ans, numb);
    }
    */
    /* way 2*/
    int carry1 = 0;
    int bufn;
    for(i = 0; i < N; i++){
        bufn = (N - i) * A + carry1;
        if(i != N -1){
           carry1 = (bufn) / 10; 
           ans += to_string(bufn % 10);
        }else{
            ans += to_string(bufn);
        }
    }
    reverse(ans.begin(), ans.end());
    if(ans == ""){
        cout << "0";
    }else{
        cout << ans;
    }
    return 0;
}