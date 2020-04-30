#include <stdio.h>
#include <string.h>
#define N 222222
int n, inp[N], tmp[N], res[N], ind;
int ceil_ind(int val){
    int l=0, r=ind, m, ret=-1;
    while (l<=r){
        m=(l+r)/2;
        if (tmp[m]<val)
            l=m+1;
        else
            ret=m, r=m-1;
    }
    return ret;
}
void longest_increasing_subsequence(void){
    memset(res, -1, sizeof(res));
    for (int i=1; i<n; i++){
        if (inp[tmp[ind]]<inp[i])
            res[i]=tmp[ind],
            tmp[++ind]=i;
        else{
            int crnt=ceil_ind(inp[i]);
            tmp[crnt]=i;
            res[tmp[crnt]]=tmp[crnt-1];
        }
    }
}
void output(int val){
    if (val==-1)
        return;
    if (val!=-1)
        output(res[val]);
    printf("%d ", inp[val]);
}
int main(){
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &inp[i]);
    longest_increasing_subsequence();
    printf("%d\n", ind+1);
    output(tmp[ind]);
}
