import sys
LI=lambda:list(map(int, sys.stdin.readline().strip('\n').split()))
MI=lambda:map(int, sys.stdin.readline().strip('\n').split())
SI=lambda:sys.stdin.readline().strip('\n')
II=lambda:int(sys.stdin.readline().strip('\n'))

def TSCC(u):
	global g, low, num, onStack, cnt, stack, numSCC
	cnt+=1
	num[u]=low[u]=cnt
	onStack[u]=True
	stack.append(u)
	for v in g[u]:
		if num[v]==-1:
			TSCC(v)
			low[u]=min(low[u], low[v])
		if onStack[v]:
			low[u]=min(low[u], num[v])
	if low[u]==num[u]:
		numSCC+=1
		while True:
			v=stack.pop()
			onStack[v]=False
			print(v, end=' ')
			if u==v:
				break
		print()

n=II()
g, num, low, onStack={}, {}, {}, {}
cnt, stack, numSCC=0, [], 0
for i in range(1, n+1):
	g[i], num[i], low[i], onStack[i]=[], -1, 0, False
for u in range(1, n+1):
	v=II()
	g[u].append(v)
for u in range(1, n+1):
	if num[u]==-1:
		TSCC(u)
print(numSCC)
