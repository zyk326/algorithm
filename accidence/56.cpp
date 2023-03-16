#include<iostream>
#include<stack>

using namespace std;

struct Shai{
    stack <int>st;
};
Shai ss[6];
int i = 0, j, k;
int buf, n;

int main(){
    for(i = 0; i < 6; i++){
        cin >> buf;
        for(j = 1; j <= 6; j++){
            if(j != buf)
                ss[i].st.push(j);
        }
    }
    cin >> n;
    for(i = 0; i < n; i++){
        for(j = 0; j < 6; j++){
            if(i == n - 1){
                cout << ss[j].st.top();  
                if(j != 5){
                    cout << " ";
                }  
            }
            
            ss[j].st.pop();
        }
    }
    return 0;
}