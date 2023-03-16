// #include<iostream>
// #include<algorithm>
// #include<vector>

// using namespace std;

// int N, K, S;
// int point;
// int i, j;

// struct peo{
//     int tianti;
//     int pta;
//     int ined;
//     bool operator <(peo const &a) const{
//         if(tianti < a.tianti){
//             return true;
//         }else if(tianti > a.tianti){
//             return false;
//         }else{
//             return pta > a.pta;
//         }
//     }
// };
// vector<peo>peos;
// peo pes;

// int main(){
//     cin >> N >> K >> S;
//     for(i = 0; i < N; i++){
//         cin >> pes.tianti;
//         cin >> pes.pta;
//         pes.ined = 0;
//         peos.push_back(pes);
//     }
//     sort(peos.begin(), peos.end());
//     // for(i = 0; i < N; i++){
//     //     cout << peos[i].tianti << " " << peos[i].pta << endl;
//     // }
//     point = 0;
//     while(K > 0){
//         int buftianti = 0;
//         bool locktianti = false;
//         for(i = 0; i < peos.size() && i >= 0; i++){
//             // cout << " now : " << peos[i].tianti << " - " << peos[i].pta << " | " << "inis : " << peos[i].ined << "  --  ";
//             // if(!peos[i].ined){
//                 if(peos[i].tianti < 175){
//                     peos.erase(peos.begin() + i);
//                     i--;
//                     continue;
//                 }
//                 if(buftianti != peos[i].tianti){
//                     locktianti = false;
//                 }
//                 // cout << "lock status is : " << locktianti << " | ";
//                 if(peos[i].tianti >= 175){  
//                     if(peos[i].pta >= S){   //特殊
//                         // cout << "is a special course. ";
//                         point++;
//                         i--;
//                         peos[i].ined = 1;
//                         peos.erase(peos.begin() + i);
//                         continue; 
//                     }else{
//                         if(!locktianti){
//                             locktianti = true;
//                             point++;
//                             i--;
//                             buftianti = peos[i].tianti;
//                             peos[i].ined = 1;
//                             peos.erase(peos.begin() + i);
//                             // cout << "is a common course. ";
//                         }
//                     }
//                 }
//             // }
//             // cout << " now buftianti is : " << buftianti << "now point is : " << point << endl;
//         }
//         K--;
//     }
//     cout << point;
//     return 0;
// }

#include<iostream>
#include<algorithm>

using namespace std;

int N, K, S;
int point;
int i, j;

struct peo{
    int tianti;
    int pta;
    int ined;
    bool operator <(peo const &a) const{
        if(tianti < a.tianti){
            return true;
        }else if(tianti > a.tianti){
            return false;
        }else{
            return pta > a.pta;
        }
    }
}peos[100000];

int main(){
    cin >> N >> K >> S;
    for(i = 0; i < N; i++){
        cin >> peos[i].tianti;
        cin >> peos[i].pta;
        peos[i].ined = 0;
    }
    sort(peos, peos + N);
    point = 0;
    while(K > 0){
        int buftianti = 0;
        bool locktianti = false;
        for(i = 0; i < N; i++){
            // cout << " now : " << peos[i].tianti << " - " << peos[i].pta << " | " << "inis : " << peos[i].ined << "  --  ";
            if(!peos[i].ined){
                if(buftianti != peos[i].tianti){
                    locktianti = false;
                }
                // cout << "lock status is : " << locktianti << " | ";
                if(peos[i].tianti >= 175){  
                    if(peos[i].pta >= S){   //特殊
                        // cout << "is a special course. ";
                        point++;
                        peos[i].ined = 1;
                        continue; 
                    }else{
                        if(!locktianti){
                            locktianti = true;
                            point++;
                            buftianti = peos[i].tianti;
                            peos[i].ined = 1;
                            // cout << "is a common course. ";
                        }
                    }
                }
            }
            // cout << " now buftianti is : " << buftianti << "now point is : " << point << endl;
        }
        K--;
    }
    cout << point;
    return 0;
}