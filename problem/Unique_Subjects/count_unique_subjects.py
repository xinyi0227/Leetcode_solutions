import pandas as pd

def count_unique_subjects(teacher: pd.DataFrame) -> pd.DataFrame:
    teacher.drop(columns=["dept_id"],inplace=True)
    df = teacher.groupby("teacher_id").nunique().reset_index()
    df.rename(columns={"subject_id":"cnt"},inplace=True)
    return df
    