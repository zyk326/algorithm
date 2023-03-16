#include<iostream>
#include<regex>

using namespace std;

int N;
string identity[101];
int i, j = 0;
int point = 0;
regex reg("[0-9]");
string buf;
int buf1;
int rulebefore[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
int M[11] = {1, 0, -1, 9, 8, 7, 6, 5, 4, 3, 2};

bool formate(string a){
    int ans = 0;
    while(j < 17){
        buf = a.substr(j, 1);
        if(!regex_match(buf, reg)){
            return false;
        }else{
            // cout << rulebefore[j] * atoi(buf.c_str()) << endl;
            ans += rulebefore[j] * atoi(buf.c_str());
            // cout << ans << endl;
        }
        j++;
    }
    // cout << ans << endl;
    ans = M[ans % 11];
    // cout << a[17] << " " << ans << endl; 
    if(a[17] == 'X'){
        if(ans == -1)
            return true;
        else{
            return false;
        }
    }else{
        buf = a.substr(17, 1);
        return atoi(buf.c_str()) == ans; 
    }
}
 
int main(){
    cin >> N;
    for(i = 0; i < N; i++){
        cin >> identity[i];
        j = 0;
        if(!formate(identity[i])){
            
            identity[point++] = identity[i];
        }
    }
    // cout << point << endl;
    if(point == 0){
        cout << "All passed";
    }else{
        for(i = 0; i < point; i++){
            cout << identity[i] << endl;
        } 
    }
    return 0;
}