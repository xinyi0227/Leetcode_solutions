import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    self_viewing_authors = views.query('author_id == viewer_id')['author_id'].unique()
    return pd.DataFrame({'id': sorted(self_viewing_authors)})
