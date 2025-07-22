import pandas as pd

def exchange_seats(seat: pd.DataFrame) -> pd.DataFrame:
    seat['new_id'] = seat.apply(lambda x: x['id']-1 if x['id']%2==0 else x['id']+1,axis=1)

    if seat.shape[0]%2 != 0:
        seat['new_id'].iloc[-1] = seat.shape[0]

    return seat[['new_id','student']].rename(columns={'new_id':'id'}).sort_values('id')