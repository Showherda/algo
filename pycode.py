import sys
LI=lambda:list(map(int, sys.stdin.readline().strip('\n').split()))
MI=lambda:map(int, sys.stdin.readline().strip('\n').split())
SI=lambda:sys.stdin.readline().strip('\n')
II=lambda:int(sys.stdin.readline().strip('\n'))

n=II()
s, t=SI(), SI()						# match t in 2*s
s*=2
lps=[0]*n							# longest prefix that is also a suffix
j=0
for i in range(1, n):
	if t[j]==t[i]:
		lps[i]=j+1
		j+=1
	else:
		while j!=0 and t[j]!=t[i]:
			j=lps[j-1]				# we know that a common prefix-suffix has been found at j-1
		if t[j]==t[i]:
			lps[i]=j+1
			j+=1
		else:
			lps[i]=0
i, j=0, 0
while i<2*n:
	if j==n:
		print(2*n-i if i!=n else 0)
		exit()
	if s[i]==t[j]:
		i+=1
		j+=1
	else:
		if j:
			j=lps[j-1]				# t[0:j] has been matched, so find the lps at j-1
		else:
			i+=1
print(-1)