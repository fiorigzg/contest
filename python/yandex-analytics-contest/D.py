deadline = int(input())
tasks = list(map(int, input().split()))

res = max(tasks) + 1
l = 1
r = max(tasks) + 1
while l != r:
  m = (l + r) // 2

  days = 0
  for task in tasks:
    days += task // m + (1 if task % m != 0 else 0)

  if days <= deadline:
    res = m
    r = m
  else:
    l = m + 1

print(res)