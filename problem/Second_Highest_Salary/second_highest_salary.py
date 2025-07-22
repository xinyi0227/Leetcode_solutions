import pandas as pd

def second_highest_salary(employee: pd.DataFrame) -> pd.DataFrame:
    employee['rank'] = employee['salary'].rank(method = 'dense',ascending = False)
    second = employee[employee['rank']==2]
    return pd.DataFrame({'SecondHighestSalary':[None if len(second)==0 else second['salary'].iloc[0]]})