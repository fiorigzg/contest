import pandas as pd
import numpy as np
from datetime import datetime

# df = pd.DataFrame(np.array([
# 	[0,26,1708104067,74,95],
# 	[1,40,1707585667,25,46],
# 	[2,48,1704993667,50,99],
# 	[3,15,1704475267,32,15],
# 	[4,38,1706030467,84,83],
# ]), columns=['id','user_id','timestamp','billing_period','billing_total_price_usd'])

def process(df):
	start_date = datetime(2024, 2, 1, 0, 0, 0)
	end_date = datetime(2024, 2, 29, 0, 0, 0)
	
	df['date_start'] = df['timestamp'].apply(datetime.fromtimestamp)
	df['timestamp'] = df['timestamp'] + df['billing_period'].apply(lambda el: (el-1)*60*60*24)
	df['date_end'] = df['timestamp'].apply(datetime.fromtimestamp)

	df = df.drop(columns=['timestamp'])
	df = df.drop(df[df.date_end < start_date].index)
	df = df.drop(df[df.date_start > end_date].index)

	df.loc[df['date_start'] < start_date, 'date_start'] = start_date
	df.loc[df['date_end'] > end_date, 'date_end'] = end_date

	df['fin_cont'] = df['billing_total_price_usd'] / df['billing_period']
	df['days_in_feb'] = df['date_end'] - df['date_start']
	df['days_in_feb'] = df['days_in_feb'].apply(lambda el: el.days + 1)
	df['feb_fin_cont'] = df['fin_cont'] * df['days_in_feb']
	
	res = df.groupby('user_id')['feb_fin_cont'].sum().nlargest(3).sum()

	return round(res, 2)

# print(process(df))