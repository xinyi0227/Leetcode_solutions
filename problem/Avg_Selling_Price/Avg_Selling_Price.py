import pandas as pd

def average_selling_price(prices: pd.DataFrame, units_sold: pd.DataFrame) -> pd.DataFrame:

    all_products = prices[['product_id']].drop_duplicates()

    merged = units_sold.merge(prices, on='product_id')

    valid_sales = merged[
        (merged['purchase_date'] >= merged['start_date']) & 
        (merged['purchase_date'] <= merged['end_date'])
    ]
    
    if not valid_sales.empty:
        valid_sales['revenue'] = valid_sales['units'] * valid_sales['price']
        product_stats = valid_sales.groupby('product_id').agg({
            'revenue': 'sum',
            'units': 'sum'
        }).reset_index()
        product_stats['average_price'] = (product_stats['revenue'] / product_stats['units']).round(2)
        result_with_sales = product_stats[['product_id', 'average_price']]
    else:
        result_with_sales = pd.DataFrame(columns=['product_id', 'average_price'])
    
    result = all_products.merge(result_with_sales, on='product_id', how='left')
    result['average_price'] = result['average_price'].fillna(0.0)
    
    return result
