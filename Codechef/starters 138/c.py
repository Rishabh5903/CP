from sys import stdin, stdout
input = stdin.readline
from bisect import bisect, bisect_right, bisect_left
from math import inf, ceil, log2, gcd, lcm, sqrt, log,floor
from heapq import heapify, heappop, heappush
from collections import Counter, deque
for _ in range(int(input())):
    #n,m=map(int,input().split())
    n=int(input())
    if(n==1):
        print(1)
        continue
    ans=[3]*(n-2)+[2,1]

    print(*ans)
    #s=str(input())
    #s=s[:len(s)-1]
    #l=list(map(int,input().split()))
    #l[:0]=s
