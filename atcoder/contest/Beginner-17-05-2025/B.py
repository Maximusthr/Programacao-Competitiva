n, t = map(int, input().split())
arr = list(map(int, input().split()))

display = 1
for i in range(n):
    display *= arr[i]
    temp = display
    count = 0
    while temp > 0:
        count += 1
        temp //= 10
    if count > t or temp < 0 or display == 0:
        display = 1

print(display)
