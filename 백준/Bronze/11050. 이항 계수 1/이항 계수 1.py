import sys
import math
input = sys.stdin.readline

# 입력
n, k = map(int, input().split())

# 이항계수 공식
print(math.factorial(n) // (math.factorial(k) * math.factorial(n-k)))