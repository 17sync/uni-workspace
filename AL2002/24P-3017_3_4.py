import pandas as pd
import numpy as np

df=pd.DataFrame({
    "ID": [1, 2, 3, 4, 2, 5],
    "Name": ["Ali", "Sara", "John", "Ahmed", "Sara", None],
    "Department": ["IT", "I.T.", "HR", "Information Technology", "I.T.", "Finance"],
    "Salary": [60000, np.nan, 50000, np.nan, 55000, np.nan],
    "Join Date": ["2023-01-10", "2023-02-15", "2022-05-20", "2024-01-10", "2023-02-15", "2023-09-10"],
    "Email": ["ali@company.com", np.nan, "john@company.com", "ahmed@company.com", np.nan, "usman@company.com"]
})

print("Missing values:\n", df.isnull().sum())

df=df.drop_duplicates()
df=df.dropna(subset=["ID", "Name"])

df["Department"]=df["Department"].replace({
    "I.T.": "IT",
    "Information Technology": "IT"
})

df["Salary"]=df.groupby("Department")["Salary"].transform(
    lambda x: x.fillna(x.median())
)

df["Email"]=df.apply(
    lambda x: x["Name"].lower()+"@company.com"
    if pd.isna(x["Email"]) else x["Email"], axis=1
)

df["Join Date"]=pd.to_datetime(df["Join Date"])

print("\nCleaned Data:")
print(df)

print("\nStatistics:")
print(df.describe())