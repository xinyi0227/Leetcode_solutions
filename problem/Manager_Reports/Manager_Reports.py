import pandas as pd

def find_managers(employee: pd.DataFrame) -> pd.DataFrame:

    manager_counts = employee.groupby('managerId').size().reset_index(name='direct_reports')

    qualified_managers = manager_counts[manager_counts['direct_reports'] >= 5]
    
    result = employee[employee['id'].isin(qualified_managers['managerId'])][['name']]
    
    return result
