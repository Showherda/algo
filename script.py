import sys
LI=lambda:list(map(int, sys.stdin.readline().strip('\n').split()))
MI=lambda:map(int, sys.stdin.readline().strip('\n').split())
SI=lambda:sys.stdin.readline().strip('\n')
II=lambda:int(sys.stdin.readline().strip('\n'))

class Node:
	def __init__(self, val):
		self.val=val
		self.parent=None
		self.left=None
		self.right=None
	def minimum(self, parent):
		if self.left:
			return self.left.minimum(self)
		else:
			return [parent, self]
	def insert(self, val):
		if val<self.val:
			if self.left:
				self.left.insert(val)
			else:
				self.left=Node(val)
				self.left.parent=self
		elif val>self.val:
			if self.right:
				self.right.insert(val)
			else:
				self.right=Node(val)
				self.right.parent=self
		else:
			self.val=val
	def delete(self, val):
		if self.val==val:
			if self.left and self.right:
				ps, s=self.right.minimum(self)
				if ps.left==s:
					ps.left=s.right
				else:
					ps.right=s.right
				s.parent=self.parent
				s.left=self.left
				s.right=self.right
				return s
			elif self.left:
				self.left.parent=self.parent
				if self.parent:
					if self.parent.left==self:
						self.parent.left=self.left
					else:
						self.parent.right=self.left
				return self.left
			elif self.right:
				self.right.parent=self.parent
				if self.parent:
					if self.parent.left==self:
						self.parent.left=self.right
					else:
						self.parent.right=self.right
				return self.right
			else:
				if self.parent:
					if self.parent.left==self:
						self.parent.left=None
					else:
						self.parent.right=None
				return None
		else:
			if self.val>val:
				if self.left:
					self.left=self.left.delete(val)
			else:
				if self.right:
					self.right=self.right.delete(val)
		return self
	def query(self, val, k):

	def inorder(self):
		if self.left:
			self.left.inorder()
		print(self.val)
		if self.right:
			self.right.inorder()
n, k=MI()
root=Node(n//2+1)
for i in range(n//2+2, n+1):
	root.insert(i)
for i in range(n//2, 0, -1):
	root.insert(i)
