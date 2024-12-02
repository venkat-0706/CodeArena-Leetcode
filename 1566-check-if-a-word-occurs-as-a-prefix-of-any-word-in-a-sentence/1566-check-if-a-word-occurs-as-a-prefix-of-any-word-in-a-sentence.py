class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        # Split the sentence into words
        words = sentence.split(" ")
        
        # Iterate over the words
        for i, word in enumerate(words):
            # Check if the word starts with the searchWord
            if word.startswith(searchWord):
                return i + 1  # Return 1-based index
        
        # Return -1 if no word starts with the searchWord
        return -1