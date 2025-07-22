import pandas as pd

def consecutive_numbers(logs: pd.DataFrame) -> pd.DataFrame:
    logs.sort_values('id', ascending=True, inplace=True)
    logs['previous'] = logs['num'].shift(1)
    logs['next'] = logs['num'].shift(-1)
    result = logs[(logs['num'] == logs['previous']) & (logs['num'] == logs['next'])]
    return result.drop_duplicates(subset='num', keep='first').rename(columns={'num': 'ConsecutiveNums'})[['ConsecutiveNums']]