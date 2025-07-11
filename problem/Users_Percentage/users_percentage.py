import pandas as pd

def users_percentage(users: pd.DataFrame, register: pd.DataFrame) -> pd.DataFrame:

    total_users = len(users)

    contest_counts = register.groupby('contest_id').size().reset_index(name='registered_users')

    contest_counts['percentage'] = (contest_counts['registered_users'] / total_users * 100).round(2)

    result = contest_counts.sort_values(['percentage', 'contest_id'], ascending=[False, True])
    
    return result[['contest_id', 'percentage']]
