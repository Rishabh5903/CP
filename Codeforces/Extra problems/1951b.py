from sys import stdin, stdout
input = stdin.readline
from bisect import bisect, bisect_right, bisect_left
from math import inf, ceil, log2, gcd, lcm, sqrt, log,floor
from heapq import heapify, heappop, heappush
from collections import Counter, deque
for _ in range(int(input())):
    n,k=map(int,input().split())
    #n=int(input())
    #s=str(input())
    #s=s[:len(s)-1]
    l=list(map(int,input().split()))
    ind1=0
    ind2=0
    for i in range(k):
        if(l[i]>l[k-1]):
            ind1=i
            break
    for i in range(k-1,-1,-1):
        if(l[i]>l[k-1]):
            ind2=i
            break
    print(max(ind1,k-ind2-1))
    #l[:0]=s
