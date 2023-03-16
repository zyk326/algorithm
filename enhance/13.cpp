#include<iostream>

using namespace std;

int fa[10005],cnt[10005];
int n,m,x,y,i;

int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}

int main(){
    while(scanf("%d",&n)!=EOF&&n){
        scanf("%d",&m);
        for(i=0;i<10005;i++) 
            fa[i]=i,cnt[i]=0;
        while(m--){
            scanf("%d%d",&x,&y);
            int fax=find(x),fay=find(y);
            if(fax-fay) fa[fax]=fay;
            cnt[x]++,cnt[y]++;
        }
        int f=find(1),flag=1;
        if(cnt[1]%2) 
            flag=0;
        for(i=2;i<=n;i++)
            if((cnt[i]&&find(i)!=f)||cnt[i]%2){
                flag=0;
                break;
            }
        printf("%d\n",flag);
    }
}