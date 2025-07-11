import pandas as pd

def invalid_tweets(tweets: pd.DataFrame) -> pd.DataFrame:
    invalid_mask = tweets['content'].str.len() > 15

    return tweets[invalid_mask][['tweet_id']]
