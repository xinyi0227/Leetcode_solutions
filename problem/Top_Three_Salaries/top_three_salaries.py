import pandas as pd

def filter(row):
    row['rank'] = row["salary"].rank(method="dense",ascending=False)
    return row[row["rank"]<=3]

def top_three_salaries(employee: pd.DataFrame, department: pd.DataFrame) -> pd.DataFrame:
    merged = pd.merge(employee,department,left_on="departmentId",right_on="id",how="left")
    ans = merged.groupby(["name_y"])\
        .apply(filter)\
        .rename(columns={
            "name_x":"Employee",
            "name_y":"Department",
            "salary":"Salary"
        })
    return ans[["Department","Employee","Salary"]]