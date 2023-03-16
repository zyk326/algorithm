#include<iostream>

using namespace std;

int N;
int i, j;
string str1[100];
string str;
int ans[100];

int main(){
    cin >> N;
    for(i = 0; i < N; i++){
        cin >> str1[i];
    }
    for(i = 0; i < N; i++){
        str = str1[i];
        if(str.length() < 8 || str.length() > 16){
            ans[i] = 0;
            continue;
        }
        int t, k, l, g;
        for(j = 0; j < str.length(); j++){
            if(str[j]>='0'&& str[j]<='9')
                t=1;
            if(str[j]>='a'&& str[j]<='z')
                k=1;
            if(str[j]>='A'&& str[j]<='Z')
                l=1;
            if(str[j]=='~'||str[j]=='@'|| str[j]=='#'||str[j]=='$'||str[j]=='%'|| str[j]=='^')
                g=1;
        }
        if(t + k + l + g >= 3){
            ans[i] = 1;
        }else{
            ans[i] = 0;
        }
    }
    for(i = 0; i < N; i++){
        if(ans[i] == 0){
            cout << "NO" << endl;
        }else if(ans[i] == 1){
            cout << "YES" << endl;
        }
    }
    return 0;
}

// #include<stdio.h>
// #include<string.h>
// int main()
// {
//  int i,j,k,t,n,g,l;
//  char a[50];
//  scanf("%d",&n);
//  getchar();
//  while(n--)
//  {
//   gets(a);
//   t=k=l=g=0;
//   for(i=0;a[i]!='\0';i++)
//   {
//    if(a[i]>='0'&&a[i]<='9')
//     t=1;
//    if(a[i]>='a'&&a[i]<='z')
//     k=1;
//    if(a[i]>='A'&&a[i]<='Z')
//     l=1;
//    if(a[i]=='~'||a[i]=='@'||a[i]=='#'||a[i]=='$'||a[i]=='%'||a[i]=='^')
//     g=1;
//   }
//   if(t+k+l+g>=3&&strlen(a)>=8&&strlen(a)<=16)
//    printf("YES\n");
//   else
//    printf("NO\n");
//  }
//  return 0;
// }