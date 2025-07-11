import pandas as pd

def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    # Using pandas query method
    return world.query('area >= 3000000 or population >= 25000000')[['name', 'population', 'area']]
