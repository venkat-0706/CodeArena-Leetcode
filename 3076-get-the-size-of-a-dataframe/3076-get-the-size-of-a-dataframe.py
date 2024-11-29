import pandas as pd

def getDataframeSize(players: pd.DataFrame) -> List[int]:
    [r,c] = players.shape
    return [r,c]
    