#include<iostream>
#include<algorithm>
#include<iomanip>

using namespace std;

int N;
int point;
int i, j;
struct book{
    string name;
    double price;
    bool operator <(book const & a)const{
        if(price < a.price){
            return true;
        }else{
            return false;
        }
    }
}books[11];

int main(){
    cin >> N;
    for(i = 0; i < N; i++){
        getline(cin, books[i].name);
        getline(cin, books[i].name);
        cin >> books[i].price;
    }
    sort(books, books + N);
    cout << setprecision(2) << fixed << books[N - 1].price << ", " << books[N - 1].name << endl;
    cout << setprecision(2) << fixed << books[0].price << ", " << books[0].name;
    return 0;
}