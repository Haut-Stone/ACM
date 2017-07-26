#include <map>  
#include <set>  
#include <queue>  
#include <stack>  
#include <cmath>  
#include <ctime>  
#include <cctype>  
#include <string>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
using namespace std;  

//这题不是我写的，是网上的代码。
//http://blog.csdn.net/jhgkjhg_ugtdk77/article/details/46127581

typedef long long ll;  
  
const int maxn = 25000 + 5;   
  
struct Edge{  
    int x;  
    int y;  
}cow[maxn];  
  
int N,T;  
int X,Y;  
  
bool cmp(Edge a,Edge b){  
    if(a.x==b.x) return a.y>b.y;  
    return a.x<b.x;  
}  
  
void input(){  
    X=0; Y=0;  
    scanf("%d%d",&N,&T);  
    for(int i=0;i<N;i++){  
        scanf("%d%d",&cow[i].x,&cow[i].y);  
        if(cow[i].x==1) X=1;  
        if(cow[i].y==T) Y=1;  
    }  
}  
  
void solve(){  
    sort(cow,cow+N,cmp);  
    //若所有的牛的工作时间的起始时间和结束时间都没有覆盖掉区间的起始时间和结束时间  
    if(X==0 || Y==0){  
        printf("-1\n");  
        return ;  
    }  
    int ans=1,End=0;  
    int Start=cow[0].y;  
    int maxy=cow[0].y;  
    while(true){  
        while(End+1<N&&cow[End+1].x<=Start+1){  
            End++;  
            if(cow[End].y>maxy){  
                maxy=cow[End].y;  
            }  
        }  
        if(maxy!=Start){  
            ans++;  
            Start=maxy;  
        }  
        else{  
            if(End==N-1){ //已覆盖掉区间  
                break;  
            }  
            else{  //说明中间有的时间点覆盖不到  
                printf("-1\n");  
                return ;  
            }  
        }  
    }  
    printf("%d\n",ans);  
    return ;  
}  
  
int main(){  
    input();  
    solve();  
    return 0;  
}  