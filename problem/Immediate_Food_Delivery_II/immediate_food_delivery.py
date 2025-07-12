import pandas as pd

def immediate_food_delivery(delivery: pd.DataFrame) -> pd.DataFrame:
    first_orders =  delivery.groupby('customer_id') ['order_date'].min() .reset_index()
    first_orders_df = delivery.merge(right=first_orders, how='inner', on=['customer_id', 'order_date'])

    return pd.DataFrame({
        "immediate_percentage": [ ((first_orders_df['order_date'] == first_orders_df['customer_pref_delivery_date'])
        .mean() * 100)
        .__round__(2) ]
    })