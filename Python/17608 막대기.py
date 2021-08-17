# 17608
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

n = int(input())
lst = [int(input()) for _ in range(n)]
ans = 1
max = lst[n - 1]
for i in range(n - 1, -1, -1):
    if max < lst[i]:
        ans += 1
        max = lst[i]
print(ans)