import pandas as pd

def sales_analysis(sales: pd.DataFrame) -> pd.DataFrame:
    first_years = sales.groupby('product_id')['year'].min().reset_index()
    first_years.columns = ['product_id', 'first_year']

    result = sales.merge(first_years, on='product_id')
    result = result[result['year'] == result['first_year']]

    return result[['product_id', 'first_year', 'quantity', 'price']]
