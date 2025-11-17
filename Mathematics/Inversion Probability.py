from fractions import Fraction
from decimal import Decimal, getcontext, ROUND_HALF_EVEN

# set enough precision for final Decimal conversion
getcontext().prec = 50  

n = int(input())
r = list(map(int, input().split()))

ans = Fraction(0, 1)
for i in range(n):
    for j in range(i + 1, n):
        if r[i] <= r[j]:
            ans += Fraction(r[i] - 1, r[j] * 2)
        else:
            ans += Fraction(r[j] - 1, r[i] * 2)
            ans += Fraction(r[i] - r[j], r[i])

# convert exact Fraction to Decimal
ans_decimal = Decimal(ans.numerator) / Decimal(ans.denominator)

# round to 6 decimals, half to even
ans_str = str(ans_decimal.quantize(Decimal("0.000001"), rounding=ROUND_HALF_EVEN))

print(ans_str)
