import pandas as pd
import numpy as np

d = np.array([
  [0,26,1708104067,74,95],
  [1,40,1707585667,25,46],
  [2,48,1704993667,50,99],
  [3,15,1704475267,32,15],
  [4,38,1706030467,84,83],
])
df = pd.DataFrame(d, columns=['id', 'user_id', 'timestamp', 'billing_period', 'billing_total_price_usd'])
start = 1706734800;
end = 1709240399;

def process(df):
  df = df.rename(columns={'timestamp': 'start_ts', 'billing_period': 'days', 'billing_total_price_usd': 'billed_total'})
  df['billed'] = df['billed_total'] / df['days']
  df['end_ts'] = df['start_ts'] + df['days'] * 86400
  df = df.drop(df[(df.end_ts < start) | (df.start_ts > end)].index)

  df['period_ts'] = df['days'] * 86400
  df.loc[df['start_ts'] < start, 'start_ts'] = start;
  df.loc[df['end_ts'] > end, 'end_ts'] = end;

  df['start_period_ts'] = df['start_ts'] - start
  df['end_period_ts'] = df['end_ts'] - start

  df['from_start_days'] = (df['end_period_ts'] - df['start_period_ts']) // 86400 
  df['from_start_billed'] = df['from_start_days'] * df['billed']
  df = df.sort_values(by=['from_start_billed'], ascending=False)

  head_df = df.head(3)
  res = head_df['from_start_billed'].sum()
  print(res)
  return df

processed_df = process(df)

print(processed_df)