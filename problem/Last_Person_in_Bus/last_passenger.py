import pandas as pd

def last_passenger(queue: pd.DataFrame, ans = 1000) -> pd.DataFrame:

    queue.sort_values('turn', inplace = True)
    queue['weight'] = queue.weight.cumsum()
    
    return queue[queue.weight <= 1000].tail(1)[['person_name']]