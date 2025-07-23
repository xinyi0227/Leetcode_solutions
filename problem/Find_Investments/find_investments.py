import pandas as pd

def find_investments(insurance: pd.DataFrame) -> pd.DataFrame:
  uniq_lat_lon = insurance.drop_duplicates(subset = ['lat','lon'], keep = False).pid
  not_uniq_tiv_2015 = insurance.loc[insurance.duplicated(subset = 'tiv_2015', keep=False)].pid
  df = insurance.loc[insurance.pid.isin(uniq_lat_lon) & insurance.pid.isin(not_uniq_tiv_2015)]
  return df[['tiv_2016']].sum().to_frame('tiv_2016').round(2)