import sys
LI=lambda:list(map(int, sys.stdin.readline().strip('\n').split()))
MI=lambda:map(int, sys.stdin.readline().strip('\n').split())
SI=lambda:sys.stdin.readline().strip('\n')
II=lambda:int(sys.stdin.readline().strip('\n'))

_s=list(SI())
n=len(_s)*2+1
s=['#' if i%2==0 else _s[i//2] for i in range(n)]

lsp, c, r, maxLen, ind=[1]*n, 0, 0, 0, 0
for i in range(n):
	mirror=2*c-i
	if i<r:
		lsp[i]=min(r-i, lsp[mirror])
	a, b=i+lsp[i], i-lsp[i]
	while a<n and b>=0 and s[a]==s[b]:
		lsp[i]+=1
		a+=1
		b-=1
	if i+lsp[i]>r:
		c, r=i, i+lsp[i]
		if lsp[i]>maxLen:
			maxLen=lsp[i]
			ind=i
ans=''.join(list(filter(lambda x:x!='#',s[ind-maxLen+1:ind+1]+s[ind+1:ind+maxLen])))
print(ans)
