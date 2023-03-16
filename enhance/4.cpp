#include<iostream>
#include<map>

using namespace std;

int N;
string head;
int i, j, point;
string start;

struct node{
    string pre;
    string data;
    string next;
}nodes[100001], ans[100001];
node cmp;
map<string, node> msn;
string da, ne;

int main(){
    cin >> head;
    cin >> N;
    start = head;
    for(i = 0; i < N; i++){
        if(i > 100000){
            N = 100000;
            break;
        }
        cin >> da;
        cin >> msn[da].data;
        cin >> msn[da].next;
    }
    while(start != "-1"){
        // cout << start << endl;
        nodes[point].pre = start;
        nodes[point].data = msn[start].data;
        nodes[point++].next = msn[start].next;
        start = msn[start].next;
    }
    // 构造出正确的链表
    // for(i = 0; i < point; i++){
    //     cout << nodes[i].pre << " " << nodes[i].data << " " << nodes[i].next << endl;
    // }

    /**
     * @brief 变换
     * 
     */
    // cout << endl;

    for(i = 0; i * 2 < point; i++){
        ans[j].pre = nodes[point - i - 1].pre;
        if(i != 0)
            ans[j - 1].next = ans[j].pre;
        ans[j].data = nodes[point - i - 1].data;
        ans[j++].next = nodes[i].pre;        
        ans[j].pre = nodes[i].pre;
        ans[j].data = nodes[i].data;
        if((i + 1) * 2 < point)
            ans[j++].next = nodes[i].next;
        else
            ans[j++].next = "-1";
        // cout << nodes[point - i - 1].pre << " " << nodes[point - i - 1].data << " " << nodes[point - i - 1].next << endl;
        // cout << nodes[i].pre << " " << nodes[i].data << " " << nodes[i].next << endl;
    }
    ans[point - 1].next = "-1";
    for(i = 0; i < N; i++){
        if(i != 0)
            cout << endl;
        cout << ans[i].pre << " " << ans[i].data << " " << ans[i].next;
    }
    return 0;
}