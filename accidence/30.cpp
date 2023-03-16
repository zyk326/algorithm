#include<iostream>
#include<algorithm>
#define MaxSize 1001

using namespace std;

int A;
string ele = "";
int nums[MaxSize];
int i = 0, j = 0;
int point = 0;

void init(){
    string buf;
    ele = to_string(A);
    ele.append(to_string(A + 1));
    ele.append(to_string(A + 2));
    ele.append(to_string(A + 3));
}

void swap(string &dd, int i, int j){
    char jjj = dd[i];
    dd[i] = dd[j];
    dd[j] = jjj;
}

void deal(string buf){
    nums[point] = atoi(buf.c_str());
    point++;
    swap(buf, 0, 1);
    nums[point] = atoi(buf.c_str());
    swap(buf, 0, 1);
    point++;
    swap(buf, 0, 2);
    nums[point] = atoi(buf.c_str());
    swap(buf, 0, 2);
    point++;
    swap(buf, 1, 2);
    nums[point] = atoi(buf.c_str());
    swap(buf, 1, 2);
    point++;

    swap(buf, 0, 1);
    swap(buf, 1, 2);
    nums[point] = atoi(buf.c_str());
    swap(buf, 0, 1);
    swap(buf, 0, 2);
    point++;

    swap(buf, 0, 2);    
    swap(buf, 1, 2);
    nums[point] = atoi(buf.c_str());
    swap(buf, 1, 2);
    swap(buf, 0, 2);
    point++;
}

void show(){
    for(i = 0; i < 4; i++){
        string buf = "";
        for(j = 0; j < 4; j++){
            if(j != i)
                buf += ele[j];
        }
        //抽元素
        // cout << buf << endl;
        deal(buf);
    }
    sort(nums, nums + point);
}

int main(){
    cin >> A;
    init();
    show();
    // cout << endl;
    for(int m = 0; m < point; m++){
        if(m % 6 == 0 && m != 0){
            cout << endl;
        }
        cout << nums[m];
        if((m + 1) % 6 != 0)
            cout << " ";
    }
    return 0;
}