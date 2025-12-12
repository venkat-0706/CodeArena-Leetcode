class Solution:
    def countMentions(self, n: int, events: List[List[str]]) -> List[int]:
        mention = [0]*n
        back = [0]*n
        events.sort(key=lambda e: (int(e[1]),e[0]=="MESSAGE"))
        for typ  , t , data in events:
            t = int(t)
            if typ == "OFFLINE":
                back[int(data)] = t+60
                continue

            for tok in data.split():
                if tok == "ALL":
                    for u in range(n):
                        mention[u] += 1
                elif tok == "HERE":
                    for u in range(n):
                        if t >= back[u]:
                            mention[u] += 1
                else:
                    mention[int(tok[2:])]+=1
        return mention

        