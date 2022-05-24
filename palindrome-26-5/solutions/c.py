s = input()
ans = 0
for i in range (len(s)):
	l = i - 1
	r = i + 1
	ws = set(s[i])
	ans += 1
	while l >= 0 and r < len(s) and s[l] == s[r]:
		if s[l] in ws:
			break
		ws.add(s[l])
		ans += 1
		l -= 1
		r += 1
for i in range (len(s) - 1):
	l = i
	r = i + 1
	ws = set()
	while l >= 0 and r < len(s) and s[l] == s[r]:
		if s[l] in ws:
			break
		ws.add(s[l])
		ans += 1
		l -= 1
		r += 1
print(ans)