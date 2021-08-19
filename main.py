# 1024
import collections      # 가장 많은 숫자, deque 등
import sys              # 여러줄 입력
import re               # 문자 제거
import string           # 문자열 함수
import copy             # 깊은 복사
import itertools        # 순열 조합(permutations, combinations)
import math             # 수학
import bisect           # 이진 탐색
import pprint           # 출력
from decimal import *   # 임의 정밀도
import random

n, l = map(int, input().split())

while l <= 100:
    flag = False
    for i in range(0, n - l + 1):
        lst = []
        for j in range(i, i + l):
            lst.append(j)
        if sum(lst) == n:
            flag = True
            break
    if flag:
        break
    l += 1

if not lst:
    print(-1)
else:
    print(*lst)