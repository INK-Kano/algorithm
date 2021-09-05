# 1010
import collections          # 가장 많은 숫자, deque 등
import sys                  # 여러줄 입력
import re                   # 문자 제거
import string               # 문자열 함수
import copy                 # 깊은 복사
import itertools            # 순열 조합(permutations, combinations)
import math                 # 수학
import bisect               # 이진 탐색
from pprint import pprint   # 출력
from decimal import *       # 임의 정밀도
import functools            # sort key 함수(cmp_to_key)
import random
input = sys.stdin.readline

lst = [0, 1]
for i in range(2, 51):
    lst.append(lst[i - 1] * i)

for _ in range(int(input())):
    a, b = map(int, input().rstrip().split())
    if a == b:
        print(1)
        continue
    print(lst[b]//(lst[b-a]*lst[a]))