from decimal import Decimal, getcontext, ROUND_HALF_UP
import sys

input = sys.stdin.readline

# 충분히 크게 잡아야 반올림 오차를 피할 수 있음
getcontext().prec = 80

A, B, C = map(Decimal, input().split())

# pi를 Decimal로 직접 정의
PI = Decimal('3.14159265358979323846264338327950288419716939937510')
TWO_PI = PI * 2

def sin_decimal(x: Decimal) -> Decimal:
    # 삼각함수는 주기 2π를 가지므로 범위를 줄여서 계산 안정화
    x %= TWO_PI
    if x > PI:
        x -= TWO_PI

    term = x      # 첫 항
    result = x
    n = 1

    # 테일러 급수: sin x = x - x^3/3! + x^5/5! - ...
    while True:
        term *= -(x * x) / Decimal((2 * n) * (2 * n + 1))
        result += term

        # 충분히 작아지면 중단
        if abs(term) < Decimal('1e-70'):
            break
        n += 1

    return result

def f(x: Decimal) -> Decimal:
    return A * x + B * sin_decimal(x)

# 해의 범위
left = (C - B) / A
right = (C + B) / A

# 단조증가 함수이므로 이분탐색
for _ in range(200):
    mid = (left + right) / 2
    if f(mid) < C:
        left = mid
    else:
        right = mid

answer = (left + right) / 2

# 소수점 여섯째 자리 반올림
print(answer.quantize(Decimal('0.000001'), rounding=ROUND_HALF_UP))