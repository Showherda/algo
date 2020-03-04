#include <stdio.h>
static int heap[111111], size;
int left(int ind) {return ind<<1;}
int right(int ind) {return ind<<1+1;}
int parent(int ind) {return ind>>1;}
void min_heapify(int ind)
{
    int l=left(ind), r=right(ind), lowest=ind;
    if (l<=size && heap[l]<heap[ind]) lowest=l;
    if (r<=size && heap[r]<heap[ind]) lowest=r;
    if (lowest!=ind)
    {
        int tmp=heap[lowest];
        heap[lowest]=heap[ind];
        heap[ind]=tmp;
        min_heapify(lowest);
    }
}
void build_min_heap(void)
{
    int i;
    for (i = size/2; i >= 1; i--) min_heapify(i);
}
void del(int val)
{
    int i, j;
    for (i = 1; i <= size; i++) if (heap[i]==val) break;
    for (j = i; j < size; j++)
    {
        int tmp = heap[j];
        heap[j]=heap[j+1];
        heap[j+1] = tmp;
    }
    size--;
    build_min_heap();
}
void output(void) {printf("%d\n", heap[1]);}
int main()
{
    int q;
    scanf("%d%*c", &q);
    while (q--)
    {
        char inp[10];
        scanf("%[^\n]%*c", inp);
        if (inp[0]=='1')
        {
            size++;
            heap[size]=inp[2]-'0';
            build_min_heap();
        }
        else if (inp[0]=='2') del(inp[2]-'0');
        else output();
    }
    return 0;
}
