#include<iostream>
#include<vector>

using namespace std;

vector <string> vs;
string str;

int main(){
    while(1){
        getline(cin, str);
        if(!str.compare("."))
            break;
        else{
            vs.push_back(str);
        }
    }
    int size = vs.size();
    if(size <= 1){
        cout << "Momo... No one is for you ...";
    }else if(size > 1 && size < 14){
        cout << vs[1] << " is the only one for you...";
    }else if(vs.size() >= 14){
        cout << vs[1] << " and " << vs[13] << " are inviting you to dinner...";
    }
    return 0;
}