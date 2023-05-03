from collections import defaultdict 
j1,j2,aim=4,3,2   
visited=defaultdict(lambda: False)
def solve(x,y):
    if (x==aim and y==0) or (x==0 and y==aim): 
        print(x,y)
        return True
    if visited[(x,y)] == False:
        print (x,y)
        visited[(x,y)] = True
        return solve(0,y) or solve(x,0) or solve(j1,y) or solve(x,j2) or solve(x+min(y,j1-x),y-min(y,j1-x)) or solve(x-min(x,j2-y),y+min(x,j2-y))
    else:
        return False
def solve1(x,y):
    if (x==aim and y==0) or (x==0 and y==aim):
        print(x,y)
        return True
    if visited[(x,y)] == False:
        print(x,y)
        visited[(x,y)] = True
        return solve1(0,y) or solve1(x,0) or solve1(j1,y) or solve1(x,j2) or solve1(x+min(y,j1-x),y-min(y,j1-x)) or solve1(x-min(x,j2-y),y+min(x,j2-y))
    else:
        return False
print("Steps: ")
solve1 (0,0)