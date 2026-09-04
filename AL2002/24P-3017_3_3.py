import pandas as pd
import numpy as np

data={
    "Duration": [60, 60, 60, 45, 45],
    "Pulse": [110, 117, 103, 109, 117],
    "Maxpulse": [130, 145, 135, 175, 148]
}

df=pd.DataFrame(data)
df.to_csv("TestSheet.csv", index=False)
df=pd.read_csv("TestSheet.csv")

df.loc[0, "Pulse"]=115
df.loc[1, "Duration"]=65

df["Calories"]=np.array([409.1, 479.0, 340.0, 282.4, 406.0])
df.to_csv("TestSheet.csv", index=False)

print(df)