#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <queue>
#define V 60100
#define E 1000100
#define inf 99999999
using namespace std;
int vis[V];
int dist[V];
int pre[V];

int Abs(int a){
    if(a<0) return 0-a;
    else return a;
}

struct Edge{
    int u,v,c,cost,next;
}edge[E];
int head[V],cnt;

void init(){
    cnt=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int c,int cost)
{
    edge[cnt].u=u;
    edge[cnt].v=v;
    edge[cnt].cost=cost;
    edge[cnt].c=c;
    edge[cnt].next=head[u];
    head[u]=cnt++;

    edge[cnt].u=v;
    edge[cnt].v=u;
    edge[cnt].cost=-cost;
    edge[cnt].c=0;
    edge[cnt].next=head[v];
    head[v]=cnt++;
}

bool spfa(int begin,int end){
    int u,v;
    queue<int> q;
    for(int i=0;i<=end+2;i++){
        pre[i]=-1;
        vis[i]=0;
        dist[i]=inf;
    }
    vis[begin]=1;
    dist[begin]=0;
    q.push(begin);
    while(!q.empty()){
        u=q.front();
        q.pop();
        vis[u]=0;
        for(int i=head[u];i!=-1;i=edge[i].next){
            if(edge[i].c>0){
                v=edge[i].v;
                if(dist[v]>dist[u]+edge[i].cost){
                    dist[v]=dist[u]+edge[i].cost;
                    pre[v]=i;
                    if(!vis[v]){
                        vis[v]=true;
                        q.push(v);
                    }
                }
            }
        }
    }
    return dist[end]!=inf;
}

int MCMF(int begin,int end){
    int ans=0,flow;
    int flow_sum=0;
    while(spfa(begin,end)){
        flow=inf;
        for(int i=pre[end];i!=-1;i=pre[edge[i].u])
            if(edge[i].c<flow)
                flow=edge[i].c;
        for(int i=pre[end];i!=-1;i=pre[edge[i].u]){
            edge[i].c-=flow;
            edge[i^1].c+=flow;
        }
        ans+=dist[end];
        flow_sum += flow;
    }
    //cout << flow_sum << endl;
    return ans;
}
char mp[202][202];
int HH[V];
int HL[V];
int MH[V];
int ML[V];
int S,T;
int cm,ch;
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m),n+m)
    {
        init();
        getchar();
        for(int i = 0; i < n; i++){
            gets(mp[i]);
        }
        cm = ch = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                //printf("%c ",mp[i][j]);
                if(mp[i][j]=='H'){
                    HH[ch] = i;
                    HL[ch++] = j;
                }
                else if(mp[i][j]=='m'){
                    MH[cm] = i;
                    ML[cm++] = j;
                }
            }
        }
        cm--;
        ch--;
        S = 0;
        T = cm+ch+1;
        for(int i = 1; i <= cm; i++){
            addedge(S,i,1,0);
        }
        for(int i = 1; i <= ch; i++){
            addedge(cm+i,T,1,0);
        }
        for(int i = 1; i <= cm; i++){
            for(int j = 1; j <= ch; j++){
                int tm = Abs(HH[j]-MH[i])+Abs(HL[j]-ML[i]);
                //printf("(%d,%d)-(%d,%d),tm = %d\n",HH[j],HL[j],MH[i],ML[i],tm);
                addedge(i,cm+j,1,tm);
                //printf("(%d,%d)",i,j);
            }
        }
        int ans = MCMF(S,T);
        printf("%d\n",ans);
    }
    return 0;
}