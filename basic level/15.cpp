#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

int N;
struct days{
    int book;
    string ope;
    string times;
};
vector<days> vd;
vector<days>::iterator vdi;
int point = 0;
int bufn;
string bufs, bufss;
days bufd;
int sumtime;
int sumbooks;
struct ans{
    int anst;
    int ansb;
}finans[10];

bool borrow(int book, string sss){
	for(auto vdi = vd.begin(); vdi != vd.end(); vdi++){
		if(vdi->book == book && vdi->ope == "S"){
			vdi->times = sss;
			return true;
		}
	}
	return false;
}

int getsumtime(string start, string end){
    int m1, m2, h1, h2;
    m1 = atoi(start.substr(3, 2).c_str());
    m2 = atoi(end.substr(3, 2).c_str());
    h1 = atoi(start.substr(0, 2).c_str());
    h2 = atoi(end.substr(0, 2).c_str());
	return h2 * 60 + m2 - h1 * 60 - m1;
}

int main(){
    cin >> N;     
    while(point < N){
        cin >> bufn;
        cin >> bufs;
        cin >> bufss;
        if(bufn == 0){
            //结束了这一天，需要打印结果了
            vd.clear();
            finans[point].ansb = sumbooks;
            finans[point].anst = sumtime;
            sumtime = 0;
            sumbooks = 0;
            point++;
        }else{
            bufd.book = bufn;
            bufd.ope = bufs;
            bufd.times = bufss;
            if(bufd.ope == "S"){
				if(!borrow(bufd.book, bufss)){
                	vd.push_back(bufd);					
				}
            }else if(bufd.ope == "E"){
                for(auto vdi = vd.begin(); vdi != vd.end(); vdi++){
                    if(vdi->book == bufd.book && vdi->ope == "S"){
                        sumtime += getsumtime(vdi->times, bufd.times);
                        sumbooks++;
                        break;
                    }
                }
            }
        }
    }
    for(int i = 0; i < point; i++){
        if(finans[i].ansb != 0){
            cout << finans[i].ansb << " " << setprecision(0) << fixed << finans[i].anst * 1.0 / finans[i].ansb << endl;
        }else{
            cout << finans[i].ansb << " " << "0" << endl;
        }
    }
    return 0;
}
