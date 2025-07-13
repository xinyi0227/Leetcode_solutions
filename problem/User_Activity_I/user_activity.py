import pandas as pd

def user_activity(activity: pd.DataFrame) -> pd.DataFrame:
    start_date = '2019-06-28'
    end_date = '2019-07-27'
    activity = activity[(activity['activity_date'] >= start_date) & (activity['activity_date'] <= end_date)]
    daily_active_users = activity.groupby('activity_date')['user_id'].nunique().reset_index()
    daily_active_users.columns = ['day', 'active_users']
    return daily_active_users