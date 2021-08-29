# 1253
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
import functools        # sort key 함수(cmp_to_key)

input()
lst = list(map(int, sys.stdin.readline().strip().split()))
lst.sort()

ans = 0
for i in range(len(lst)):
    ltmp = copy.deepcopy(lst)
    ntmp = lst[i]

    del lst[i]
    left, right = 0, len(lst) - 1
    while True:
        if left >= right:
            break
        tmp = lst[left] + lst[right]
        if tmp == ntmp:
            ans += 1
            break

        if tmp > ntmp:
            right -= 1
        else:
            left += 1
    lst = copy.deepcopy(ltmp)
print(ans)