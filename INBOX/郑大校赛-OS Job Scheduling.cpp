#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Node{
    int t;
    int jobi;
}JobQueue;

bool cmp(JobQueue a, JobQueue b){
    return a.t < b.t;
}

int main(int argc, char const *argv[])
{
    int n;
    JobQueue jobs[1010];
    while(scanf("%d", &n) != EOF){
        for(int i=1;i<=n;i++){
            scanf("%d", &jobs[i].t);
            jobs[i].jobi = i;
        }
        sort(jobs+1, jobs+n+1, cmp);
        printf("%d", jobs[1].jobi);
        for (int i = 2; i <= n; ++i)
        {
            printf(" %d", jobs[i].jobi);
        }
        printf("\n");
    }
    return 0;
}