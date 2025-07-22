import pandas as pd

def movie_rating(movies: pd.DataFrame, users: pd.DataFrame, movie_rating: pd.DataFrame) -> pd.DataFrame:
    movie_rating = movie_rating.merge(movies).merge(users)
    user_id = movie_rating.groupby("name").rating.count().sort_values(ascending=False).head(1).index[0]
    movie_id = movie_rating[(movie_rating['created_at']<'2020-03-01')&(movie_rating['created_at']>'2020-01-31')].groupby("title").rating.mean().sort_values(ascending=False).head(1).index[0]
    return pd.DataFrame({"results": [user_id, movie_id]})