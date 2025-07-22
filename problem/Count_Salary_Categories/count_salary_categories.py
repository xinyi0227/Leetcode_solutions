import pandas as pd

def fun(x):
    if x<20000:
        return "Low Salary"
    elif x>=20000 and x<=50000:
        return "Average Salary"
    else:
        return "High Salary"

def count_salary_categories(accounts: pd.DataFrame) -> pd.DataFrame:
    accounts["category"] = accounts["income"].apply(fun)
    accounts.drop(columns=["income"],inplace=True)
    accounts = accounts.groupby(["category"]).count().reset_index()
    accounts.rename(columns={"account_id":"accounts_count"},inplace=True) 
    categories = ["Low Salary", "Average Salary", "High Salary"]
    accounts = accounts.set_index("category").reindex(categories, fill_value=0).reset_index()

    return accounts