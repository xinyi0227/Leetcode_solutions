import pandas as pd

def get_average_time(activity: pd.DataFrame) -> pd.DataFrame:

    pivoted = activity.pivot_table(
        index=['machine_id', 'process_id'], 
        columns='activity_type', 
        values='timestamp'
    ).reset_index()

    pivoted['processing_time'] = pivoted['end'] - pivoted['start']
    
    result = pivoted.groupby('machine_id')['processing_time'].mean().round(3).reset_index()
    
    return result
