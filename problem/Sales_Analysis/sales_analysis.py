import pandas as pd

def sales_analysis(sales: pd.DataFrame, product: pd.DataFrame) -> pd.DataFrame:

    result = sales.merge(product, on='product_id', how='inner')

    return result[['product_name', 'year', 'price']]