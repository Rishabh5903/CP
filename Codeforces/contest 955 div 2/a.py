from sys import stdin, stdout
input = stdin.readline
from bisect import bisect, bisect_right, bisect_left
from math import inf, ceil, log2, gcd, lcm, sqrt, log,floor
from heapq import heapify, heappop, heappush
from collections import Counter, deque
for _ in range(int(input())):
    a,b=map(int,input().split())
    c,d=map(int,input().split())
    if(a>b):
        a,b=b,a
        c,d=d,c
    if(a<b<c and c>d):
        print("NO")
    else:
        print("YES")
    #n=int(input())
    #s=str(input())
    #s=s[:len(s)-1]
    #l=list(map(int,input().split()))
    #l[:0]=s
