''' 
A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different

Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1
'''

def colorful(A):
    a=list(str(A))
    a = list(map(int, a))
    D={}

    for i in range(len(a)):
        j=i
        product=1
        while j<len(a):
            product=product*a[j]
            if product in D:
                return 0
            D[product]=product

            j=j+1

        if i==len(a)-1:
            for i in D:
                print(i)
            return 1


num = 23
res = colorful(num)

print(res)