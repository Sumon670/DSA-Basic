from collections import defaultdict
class Graph:
	def __init__(self):
		self.graph = defaultdict(list)
	def addEdge(self,u,v):
		self.graph[u].append(v)
		self.visited=[]
	def BFS(self,s):
		queue=[]
		queue.append(s)
		self.visited.append(s)
		while queue:
			s=queue.pop(0)
			print(s,end=" ")
			for i in self.graph[s]:
				if i not in self.visited:
					queue.append(i)
					self.visited.append(s)
	def DFSUtil(self,v,visited):
		visited[v]=True
		print(v)
		for i in self.graph[v]:
			if self.visited[i]==False:
				self.DFSUtil(i,visited)
	def DFS(self):
		visited=[False]*(len(self.graph))
		for i in range (len(self.graph)):
			if (visited[i] == False):
				self.DFSUtil(i,visited)
g = Graph()
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(1, 2)
g.addEdge(2, 0)
g.addEdge(2, 3)
g.addEdge(3, 3)
print ("Following is Breadth First Traversal"
				" (starting from vertex 2)")
g.BFS(2)
g.DFS()