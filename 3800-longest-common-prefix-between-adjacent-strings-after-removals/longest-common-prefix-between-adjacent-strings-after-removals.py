class Solution:
    def _common_prefix_len(self, a: str, b: str) -> int:
        i = 0
        while i < len(a) and i < len(b) and a[i] == b[i]:
            i += 1
        return i

    def longestCommonPrefix(self, words: list[str]) -> list[int]:
        sz = len(words)
        if sz == 1: return [0]
        if sz == 2: return [0, 0]

        pair_scores = []
        idx = 1
        limit = sz - 1 if sz % 2 else sz - 2

        while idx < limit:
            pair_scores.append((self._common_prefix_len(words[idx - 1], words[idx]), (idx - 1, idx)))
            pair_scores.append((self._common_prefix_len(words[idx], words[idx + 1]), (idx, idx + 1)))
            idx += 2

        (pair_scores.append((self._common_prefix_len(words[sz - 2], words[sz - 1]), (sz - 2, sz - 1)))
         if sz % 2 == 0 else None)

        pair_scores.sort(reverse=True)

        result = []
        first_pair = pair_scores[0]
        second_pair = pair_scores[1] if len(pair_scores) > 1 else (-1, (-1, -1))

        result.append(second_pair[0] if len(pair_scores) >= 2 and first_pair[1][0] == 0 else first_pair[0])

        mid = 1
        while mid < sz - 1:
            mid_score = self._common_prefix_len(words[mid - 1], words[mid + 1])
            f1, f2 = first_pair[1]
            s1, s2 = second_pair[1]

            result.append(
                mid_score if mid_score >= first_pair[0]
                else max(mid_score,
                         first_pair[0] if f1 != mid and f2 != mid
                         else second_pair[0] if s1 != mid and s2 != mid and len(pair_scores) > 1
                         else pair_scores[2][0] if len(pair_scores) > 2
                         else 0
                )
            )
            mid += 1

        result.append(second_pair[0] if len(pair_scores) >= 2 and first_pair[1][1] == sz - 1 else first_pair[0])
        return result
