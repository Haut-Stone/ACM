#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Node{
    int head;
    int tail;
    int mark;
    int data[10000];
}Queue;

int main(int argc, char const *argv[])
{
    int k;
    int a,b;
    int n,m;
    Queue myQueue;
    
    scanf("%d", &k);
    for(int i=0;i<k;i++){
        scanf("%d%d%d%d", &n, &a, &b, &m);
        
        myQueue.head = 0;
        myQueue.tail = 1;
        myQueue.mark = 1;
        myQueue.data[myQueue.head] = n;
        
        while(m--){
            for(int j=myQueue.head;j<myQueue.mark;j++){
                myQueue.data[myQueue.tail] = myQueue.data[j] + a;
                myQueue.tail++;
                myQueue.data[myQueue.tail] = myQueue.data[j] + b;
                myQueue.tail++;
                myQueue.head++;
            }
            myQueue.mark = myQueue.tail;
        }
        sort(myQueue.data, myQueue.data + myQueue.tail);
        printf("%d", myQueue.data[0]);
        for(int i=1;i<myQueue.tail;i++){
            if(myQueue.data[i] == myQueue.data[i-1]){
                continue;
            }else{
                printf(" %d", myQueue.data[i]);
            }
        }
        printf("\n");
    }
    return 0;
}