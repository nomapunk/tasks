s = input()
ans = 0
# нечетный паллиндром
for i in range (0, len(s)):
    used = [0] * 26
    for step in range(0, 26):
        if i - step < 0 or i + 1 + step >= len(s):
            break
        if s[i - step] != s[i + 1 + step]: 
            break
        if (used[ord(s[i - step]) - ord('a')]):
            break
        used[ord(s[i - step]) - ord('a')] = 1
        ans += 1

# четный паллиндром
for i in range (0, len(s)):
    used = [0] * 26
    for step in range(0, 26):
        if i - step < 0 or i + step >= len(s):
            break
        if s[i - step] != s[i + step]: 
            break
        if (used[ord(s[i - step]) - ord('a')]):
            break
        used[ord(s[i - step]) - ord('a')] = 1
        ans += 1
print(ans)
