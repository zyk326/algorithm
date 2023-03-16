#include<iostream>
#include<queue>

using namespace std;

int N;
int point;
int i, j;
char l, r;
int check[11];
struct node{
    int left, right;
}Nodes[11];
int head;
queue<int> qi;
int nowNode;
int ans[11];

int main(){
    cin >> N;
    for(i = 0; i < N; i++){
        cin >> l >> r;
        Nodes[i].left = l == '-' ? 10 : l - '0';
        Nodes[i].right = r == '-' ? 10 : r - '0';
        check[Nodes[i].left] = 1;
        check[Nodes[i].right] = 1;
    }
    for(i = 0; i < N; i++){
        if(!check[i])
            head = i;
    }
    //这里是层序遍历
    qi.push(head);
    while(!qi.empty()){
        nowNode = qi.front();
        qi.pop();
        if(nowNode == 10) continue;
        if(Nodes[nowNode].left == 10 && Nodes[nowNode].right == 10) ans[j++] = nowNode;
        qi.push(Nodes[nowNode].left);
        qi.push(Nodes[nowNode].right);
    }
    cout << ans[0];
    for(i = 1; i < j; i++){
        cout << " " << ans[i];
    }
    return 0; 
}