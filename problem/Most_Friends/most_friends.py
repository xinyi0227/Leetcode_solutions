import pandas as pd

def most_friends(request_accepted: pd.DataFrame) -> pd.DataFrame:
    all_ids = pd.concat([request_accepted['requester_id'], request_accepted['accepter_id']])
    friend_counts = all_ids.value_counts()
    max_friends = friend_counts.max()
    most_friends_ids = friend_counts[friend_counts == max_friends]
    result = pd.DataFrame({'id': most_friends_ids.index, 'num': most_friends_ids.values})
    result = result.sort_values('id').reset_index(drop=True)
    return result