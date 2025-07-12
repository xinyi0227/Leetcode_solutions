import pandas as pd

def gameplay_analysis(activity: pd.DataFrame) -> pd.DataFrame:

  activity["first_login"] = activity.groupby(["player_id"])[["event_date"]].transform("min")
  activity["time_dif"] = (activity["event_date"] - activity["first_login"]).dt.total_seconds()/86400

  num = activity[activity["time_dif"]==1].shape[0]
  den = len(activity["player_id"].unique())

  return pd.DataFrame({"fraction": [np.round(num/den, 2)]})

    