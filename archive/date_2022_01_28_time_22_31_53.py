# class Tree:
# 	def __init__(self, ):
# 		self.isLocked = False
# 		self.isLockable = True
# 		self.parent = None
# 		self.children = []


# def insert(root: Tree, child: Tree):
# 	root.children.append(child)
# 	root.isLockable = child.isLockable
# 	child.parent = root


# def lock(node: Tree):
# 	if node.isLockable == False:
# 		return

# 	T = node
# 	flag = False

# 	while(T != None):
# 		if (T.isLocked):
# 			flag = True
# 			break
# 		T = T.parent

# 	if flag:
# 		return

# 	else:
# 		node.isLocked = True
# 		T = node
# 		while(T != None):
# 			T.isLockable = False
# 			T = T.parent

# def unlock(node: Tree):
# 	if not node.isLocked:
# 		return

# 	node.isLocked = False
# 	T = node

# 	while(T != None):
# 		T.isLockable = True
# 		T = T.parent



# def main():
# 	root = Tree()
# 	t1 = Tree()
# 	t2 = Tree()
# 	t3 = Tree()

# 	insert(root, t1)
# 	insert(root, t2)
# 	insert(root, t3)

# 	t5 = Tree()
# 	insert(root.children[0], t5)

# 	t4 = Tree()
# 	insert(root.children[1], t4)


# 	print("t4 node is locked:")
# 	print(t4.isLocked)
# 	lock(t4)
# 	print("locking t4")
# 	print()
	
# 	print("t4 node is locked:")
# 	print(t4.isLocked)
# 	print()

# 	print("t2 node is locked:")
# 	print(t2.isLocked)
# 	print("locking t2")
# 	lock(t2)
# 	print()

# 	print("t2 node is locked:")
# 	print(t2.isLocked)

# 	unlock(t4)
# 	print("unlocking t4")
# 	print()

# 	lock(t2)
# 	print("locking t2")
# 	print("t2 node is locked:")
# 	print(t2.isLocked)


# main()


def query_game(N, A, Q, P):
	res = []
	for i in P:
		if i[0] == 1:
			A = reversed(A)

		if i[0] == 2:
			A[i[1] - 1], A[i[2] - 1] = A[i[2] - 1], A[i[1]- 1]

		if i[0] == 3:
			A = list(A)
			res.append(A.index(i[1]) + 1)

	return res



def main():
	T = int(input())
	for _ in range(T):
		N = int(input())
		A = list(map(int, input().split()))
		Q = int(input())
		P = [list(map(int, input().split())) for i in range(Q)]
		out = query_game(N, A, Q, P)
		print(" ".join(map(str, out)))

main()