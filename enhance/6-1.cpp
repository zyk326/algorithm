#include<iostream>
#include<algorithm>
#include<stack>
#include<regex>
#include<iomanip>

using namespace std;

int N;
int point = 0, sizee = 0;
int i, j;
string str, ele[1000], buf;
stack<string> sst;
regex reg("[\\+\\-\\*\\/]");
double deal1, deal2;
bool flag = true;

string deal(double one, double two, string op){
    if(op == "+") return to_string(one + two);
    if(op == "-") return to_string(one - two);
    if(op == "/") return to_string(one / two);
    if(op == "*") return to_string(one * two);
}

int main(){
    getline(cin, str);
    // cout << str.find(" ");
    while(str[point] != '\0'){
        buf = "";
        while(str[point] != '\0' && str[point] != ' '){
            buf.push_back(str[point]);
            point++;
        }
        point++;
        ele[sizee++] = buf;
    }
    // cout << " sizee IS : " << sizee << endl;
    // for(i = 0; i < sizee; i++){
    //     cout << ele[i] << " |";
    // }
    for(i = sizee - 1; i >= 0 ; i--){
        // cout << ele[i] << endl;
        if(regex_match(ele[i], reg)){
            if(sst.size() < 2){
                cout << "ERROR";
                flag = false;
                break;
            }else{
                deal1 = stod(sst.top());
                sst.pop();
                deal2 = stod(sst.top());
                sst.pop();
                sst.push(deal(deal1, deal2, ele[i]));
            }
        }else{
            sst.push(ele[i]);
        }
    }
    if(flag)
        cout << setprecision(1) << fixed << stod(sst.top());
    return 0;
}