import pandas as pd

def triangle_judgement(triangle):
    bf1 = triangle[(triangle['x'] >= triangle['y'] + triangle['z']) | (triangle['y'] >= triangle['x'] + triangle['z']) | (triangle['z'] >= triangle['x'] + triangle['y'])]
    bf1['triangle'] = 'No'
    bf2 = triangle[(triangle['x'] < triangle['y'] + triangle['z']) & (triangle['y'] < triangle['x'] + triangle['z']) & (triangle['z'] < triangle['x'] + triangle['y'])]
    bf2['triangle'] = 'Yes'
    return pd.concat([bf1,bf2])