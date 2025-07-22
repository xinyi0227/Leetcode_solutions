import pandas as pd

def find_employees(employees: pd.DataFrame) -> pd.DataFrame:
    filtered= employees[employees['salary']<30000]
    non_existing_manager= filtered['manager_id'][~filtered['manager_id'].isin(employees['employee_id'])]
    result= filtered[employees['manager_id'].isin(non_existing_manager)]
    return result[['employee_id']].sort_values(by='employee_id')
    