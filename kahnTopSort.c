#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 111
typedef struct _list{
    int v;
    struct _list *next;
} list;
int n, s[N], tmp, size, g[N][N];
list *head, *tail;
void listPush(int v){
    list *ptr=(list *) malloc(sizeof(list));
    ptr->v=v;
    ptr->next=NULL;
    if (!head){
        head=tail=ptr;
        return ;
    }
    tail->next=ptr;
    tail=ptr;
}
int main(){
    scanf("%d", &n);
    size=n;
    memset(s, 1, sizeof(s));
    for (int i=1; i<=n; i++)
        while (scanf("%d", &tmp) && tmp){
            g[i][tmp]=1;
            if (s[tmp])
                size--;
            s[tmp]=0;
        }
    while (size)
        for (int i=1; i<=n; i++)
            if (s[i]){
                s[i]=0;
                size--;
                listPush(i);
                for (int j=1; j<=n; j++)
                    if (g[i][j]){
                        g[i][j]=0;
                        int flag=1;
                        for (int u=1; u<=n; u++)
                            if (g[u][j])
                                flag=0;
                        if (flag)
                            s[j]=1,
                            size++;
                    }
            }
    while (head)
        printf("%d ", head->v),
        head=head->next;
}
