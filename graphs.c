#include <stdio.h>
#include <stdlib.h>
typedef struct _list
{
    int val;
    struct _list *next;
} list;
list *g[5555];
int n, m, s, u, v;
void add(int val, int dst)
{
    list *ptr=(list *) malloc(sizeof(list));
    ptr->val=dst;
    ptr->next=g[val];
    g[val]=ptr;
}
void display(int val)
{
    for (list *a=g[val]; a; a=a->next) printf("%d ", a->val);
}
int main()
{
    scanf("%d%d%d", &n, &m, &s);
    while (m--)
    {
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    for (int i=1; i<=n; i++)
    {
        printf("%d-> ", i);
        display(i);
        printf("\n");
    }
}
