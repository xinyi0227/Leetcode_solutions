import pandas as pd

def not_boring_movies(cinema: pd.DataFrame) -> pd.DataFrame:

    filtered = cinema[(cinema['id'] % 2 == 1) & (cinema['description'] != 'boring')]

    result = filtered.sort_values('rating', ascending=False)
    
    return result
