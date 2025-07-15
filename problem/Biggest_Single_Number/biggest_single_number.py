import pandas as pd

def biggest_single_number(my_numbers: pd.DataFrame) -> pd.DataFrame:
    df= my_numbers.groupby('num').filter(lambda x: len(x)==1)
    max_value = df['num'].max()
    return pd.DataFrame({'num':[max_value]})
    