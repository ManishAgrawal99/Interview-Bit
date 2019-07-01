'''
Find the largest continuous sequence in a array which sums to zero.

Example:


Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}
'''

def func(A):
    hmap = {0:-1}
    size = 0
    a,b,s= 0,0,0
    for i in range(len(A)):
        s += A[i]
        if s not in hmap:
            hmap[s] = i
        else:
            if i - hmap[s] > size:
                # print(hmap[s], i)
                a,b = hmap[s]+1, i
                size = i-hmap[s]
    return a,b,size

def lszero(A):
    s = 0
    for i in A:
        s += i
    if s == 0:
        return A
    
    i,j,size = func(A)
    return A[i:j+1] if size > 0 else []



A = [1,2,-2,5,-5,7,-1,-7]

B = lszero(A)

for i in B:
    print(i)