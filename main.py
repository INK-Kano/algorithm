# 10804
import collections  # 가장 많은 숫자, deque 등
import sys          # 여러줄 입력
import re           # 문자 제거
import string       # 문자열 함수
import copy         # 깊은 복사
import itertools    # 순열 조합(permutations, combinations)
import math         # 수학
import bisect       # 이진 탐색

lst = [i for i in range(1, 21)]
for i in range(10):
    n, m = map(int, input().split())
    lst[n-1:m] = lst[n-1:m][::-1]
print(*lst, end=' ')