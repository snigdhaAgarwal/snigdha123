def LCS(string1, string2):
    if len(string1) == 0 or len(string2) == 0:
        return 0

    if string1[-1] == string2[-1]:
        return 1 + LCS(string1[:-1], string2[:-1])
    else:
        return max(LCS(string1[:-1], string2), LCS(string1, string2[:-1]))

print LCS("vivek", "prakash")
print LCS("abcdeabcde", "aabbccddee")
