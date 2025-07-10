import pandas as pd

def confirmation_rate(signups: pd.DataFrame, confirmations: pd.DataFrame) -> pd.DataFrame:
    
    confirmations['confirmation_rate']=confirmations.apply(lambda x: 0 if x['action']=='timeout' else 1, axis=1)
    result = confirmations.groupby('user_id', as_index=False)['confirmation_rate'].mean().round(2)
    result = result.merge(signups['user_id'], how='right', on='user_id').fillna(0)
    return result