class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        freq = [0] * 26
        for char in s:
            freq[ord(char) - ord("a")] += 1

        result = []
        current_char_index = 25  # Start from the largest character
        while current_char_index >= 0:
            if freq[current_char_index] == 0:
                current_char_index -= 1
                continue

            use = min(freq[current_char_index], repeatLimit)
            result.append(chr(current_char_index + ord("a")) * use)
            freq[current_char_index] -= use

            if freq[current_char_index] > 0:  # Need to add a smaller character
                smaller_char_index = current_char_index - 1
                while smaller_char_index >= 0 and freq[smaller_char_index] == 0:
                    smaller_char_index -= 1
                if smaller_char_index < 0:
                    break
                result.append(chr(smaller_char_index + ord("a")))
                freq[smaller_char_index] -= 1

        return "".join(result)