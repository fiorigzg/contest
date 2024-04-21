m = int(input())
k = int(input())
values = list(map(int, input().split()))

res = -1
for i in range(k, m):
  if m > 1 and i > k and values[i] < values[i - 1]:
    continue
  
  greater_count = 0
  for j in range(i):
    if values[j] < values[i]:
      greater_count += 1
  
  if greater_count / i >= 0.9:
    res = i + 1
    break;

print(res)