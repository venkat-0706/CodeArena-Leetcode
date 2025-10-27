class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        beams, prev = 0, 0
        for row in bank:
            devices = row.count("1")
            if devices:
                beams += prev * devices
                prev = devices
        return beams