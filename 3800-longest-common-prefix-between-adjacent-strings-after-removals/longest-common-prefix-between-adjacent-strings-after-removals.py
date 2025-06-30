class Solution:
    def getLCP(self, i: int, j: int, words: list[str]) -> int:
        l = 0
        w1, w2 = words[i], words[j]
        while l < len(w1) and l < len(w2) and w1[l] == w2[l]:
            l += 1
        return l

    def longestCommonPrefix(self, words: list[str]) -> list[int]:
        n = len(words)
        result = []

        if n == 1:
            return [0]
        elif n == 2:
            return [0, 0]

        lcpPairs = []
        i = 1

        if n % 2 != 0:
            while i < n - 1:
                lcpPairs.append((self.getLCP(i - 1, i, words), (i - 1, i)))
                lcpPairs.append((self.getLCP(i, i + 1, words), (i, i + 1)))
                i += 2
        else:
            while i < n - 2:
                lcpPairs.append((self.getLCP(i - 1, i, words), (i - 1, i)))
                lcpPairs.append((self.getLCP(i, i + 1, words), (i, i + 1)))
                i += 2
            lcpPairs.append((self.getLCP(n - 2, n - 1, words), (n - 2, n - 1)))

        lcpPairs.sort(reverse=True)

        result.append(lcpPairs[1][0] if len(lcpPairs) >= 2 and lcpPairs[0][1][0] == 0 else lcpPairs[0][0])

        mid = 1
        while mid < n - 1:
            center = self.getLCP(mid - 1, mid + 1, words)
            a1, b1 = lcpPairs[0][1]
            a2, b2 = lcpPairs[1][1] if len(lcpPairs) > 1 else (-1, -1)

            if center >= lcpPairs[0][0]:
                result.append(center)
            else:
                if a1 != mid and b1 != mid:
                    result.append(max(center, lcpPairs[0][0]))
                elif a2 != mid and b2 != mid and len(lcpPairs) > 1:
                    result.append(max(center, lcpPairs[1][0]))
                elif len(lcpPairs) > 2:
                    result.append(max(center, lcpPairs[2][0]))
                else:
                    result.append(max(center, 0))
            mid += 1

        result.append(lcpPairs[1][0] if len(lcpPairs) >= 2 and lcpPairs[0][1][1] == n - 1 else lcpPairs[0][0])
        return result
