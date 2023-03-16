#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<int> vi[26];
    string s;
    cin >> s;
    int max_index = 0;
    for (int i = 0; s[i]; i++) {
        vi[s[i] - 'a'].push_back(i);
        if (s[i] > s[max_index]) max_index = i;
    }
    int index = max_index;
    while (s[index]) {
        if (s[index] == s[max_index]) {
            int size = vi[s[max_index] - 'a'].size();
            for (int i = 0; i < size; i++) {
                //只能输出不小于当前下标的字符
                if (vi[s[max_index] - 'a'][i] >= max_index) cout << s[max_index];
            }
            //更新max_index
            index = vi[s[max_index] - 'a'].back() + 1;
            max_index = index; 
            for (int i = index; s[i]; i++) {
                if (s[i] > s[max_index]) max_index = i;
            }
            continue;
        }
        index++;
    }
    return 0;
}