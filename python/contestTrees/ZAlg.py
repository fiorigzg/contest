# https://algorithm-visualizer.org/dynamic-programming/z-string-search

def zalg(s):
    n = len(s)

    zarr = [0] * n
    l, r = 0, 0
    for i in range(1, n):
        if i > r:
            l, r = i, i
            while r < n and s[r - l] == s[r]:
                r += 1
            zarr[i] = r - l
            r -= 1
        else:
            k = i - l
            if zarr[k] < r - i + 1:
                zarr[i] = zarr[k]
            else:
                l = i
                while r < n and s[r - l] == s[r]:
                    r += 1
                zarr[i] = r - l
                r -= 1
    
    return zarr

# https://algorithm-visualizer.org/dynamic-programming/knuth-morris-pratts-string-search

def kmp_prefix(s):
    n = len(s)
    res = [0] * n
    i = 0
    for j in range(1, n):
        while i > 0 and s[i] != s[j]:
            i = res[i - 1]
        if s[i] == s[j]:
            i += 1
        res[j] = i
    return res

def kmp_find(s, p):
    matches = []
    pref = kmp_prefix(p)
    n, m = len(s), len(p)
    j = 0
    for i in range(n):
        while j >= 0 and s[i] != p[j]:
            if j > 0: j = pref[j - 1]
            else: j = -1
        j += 1
        if j == m:
            j = pref[m - 1]
            matches.append(i - m + 1)
    return matches

print(kmp_find("ACBACAACCACACAACAB", "ACAACAB"))
