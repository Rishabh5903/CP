from sys import stdin, stdout
input = stdin.readline
from bisect import bisect, bisect_right, bisect_left
from math import inf, ceil, log2, gcd, lcm, sqrt, log
from heapq import heapify, heappop, heappush
from collections import Counter, deque
import string


for _ in range(int(input())):
    n,m=map(int,input().split())
    l=list(string.ascii_lowercase)
    print("".join(l[:m])*n)
    # n=int(input())
    #s=str(input())
    #s=s[:len(s)-1]
    #l=list(map(int,input().split()))
    #l[:0]=s
