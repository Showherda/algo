import sys
input=sys.stdin.readline
f=lambda :list(map(int, input().split()))
n=int(input())
a=f()
def subfun(l, m, r):
	global a
	rs=ls=-999999999999
	s=0
	for i in range(m, l-1, -1):
		s+=a[i]
		ls=max(ls, s)
	s=0
	for i in range(m+1, r+1):
		s+=a[i]
		rs=max(rs, s)
	return ls+rs
def fun(l, r):
	global a
	if l==r:
		return a[r]
	m=(l+r)//2
	return max(fun(l, m), fun(m+1, r), subfun(l, m, r))
print(fun(0, n-1))