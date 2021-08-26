# 1312
import collections      # 가장 많은 숫자, deque 등
import sys              # 여러줄 입력
import re               # 문자 제거
import string           # 문자열 함수
import copy             # 깊은 복사
import itertools        # 순열 조합(permutations, combinations)
import math             # 수학
import bisect           # 이진 탐색
import pprint           # 출력
from decimal import *   # 임의 정밀도(getcontext().prec, Decimal)
import random
import functools        # sort key 함수(cmp_to_key)

getcontext().prec = 1000001
a, b, n = map(int, sys.stdin.readline().rstrip().split())
lst = str(Decimal(a) / Decimal(b)).split(".")
lst = list(map(list, lst))

if len(lst) == 1:
    print(0)
    exit(0)

if len(lst[1]) < n:
    print(0)
    exit(0)
print(lst[1][n - 1])