import pandas as pd

def count_employees(employees: pd.DataFrame) -> pd.DataFrame:
    df_=employees.copy()
    employees['reports_count']=employees.groupby(['reports_to'])['employee_id'].transform('count')
    employees['average_age']=employees.groupby(['reports_to'])['age'].transform('mean').fillna(0).apply(lambda x: round(x + 1e-10))
    df=employees[['reports_to','reports_count','average_age']].dropna()
    df=df.drop_duplicates()
    df=df.rename(columns={'reports_to':'employee_id'})
    df=pd.merge(df_,df,on='employee_id')
    return df[['employee_id','name','reports_count','average_age']].sort_values(by='employee_id')