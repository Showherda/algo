#include <stdio.h>
#include <string.h>
#define N 222222
int tc, n, inp[N], tmp[N], res[N], ind;
int ceil_ind(int val){
    int l=0, r=ind, m, ret=-1;
    while (l<=r){
        m=(l+r)/2;
        if (inp[tmp[m]]>=val)
            ret=m, r=m-1;
        else
            l=m+1;
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
            res[tmp[crnt]]=crnt-1<0?-1:tmp[crnt-1];
        }
    }
}
void output(int crnt){
    if (crnt==-1)
        return;
    else
        output(res[crnt]);
    printf("%d ", inp[crnt]);
}
int main(){
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &inp[i]);
    longest_increasing_subsequence();
    printf("%d\n", ind+1);
//    int crnt=tmp[ind];
//    while (crnt!=-1)
//        printf("%d ", inp[crnt]), crnt=res[crnt];
    output(tmp[ind]);
}
