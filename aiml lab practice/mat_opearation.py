import numpy as np
def mat_add(a,b):
    if ((len(a)!=len(b)) or (len(a[0])!=len(b[0]))):
        return
    else:
        n=len(a)
        m=len(a[0])
        c=[0]*n
        for i in range(0,n):
            c[i]=[0]*m
        for i in range(n):
            for j in range(m):
                c[i][j] = a[i][j]+b[i][j]
        return c
def mat_sub (a,b):
    if (len(a)!=len(b)) or (len(a[0])!=len(b[0])):
        return
    else:
        n = len(a)
        m = len(a[0])
        c = [0]*n
        for i in range(n):
            c[i]=[0]*m
        for i in range(n):
            for j in range(m):
                c[i][j]=a[i][j]-b[i][j]
        return c
def mat_mul (a,b):
    r1=len(a)
    c1=len(a[0])
    r2=len(b)
    c2=len(b[0])
    if (c1!=r2):
        print("not possible")
        return
    else:
        c=[0]*r1
        for i in range(r1):
            c[i]=[0]*c2 
        for i in range(r1):
            for j in range (c2):
                for k in range (c1):
                    c[i][j] += a[i][k]*b[k][j]
        return c 

r1=int(input())
c1=int(input())
a=[[int(input()) for i in range(c1)]for i in range(r1)]
r2=int(input())
c2=int(input())
b=[[int(input()) for i in range(c2)]for i in range(r2)]
c=mat_add(a,b)
d=mat_sub(a,b)
e=mat_mul(a,b)
#print(c)  
#print (d)
print(e)
inv = np.linalg.inv(a)  #important remember   
print(inv)