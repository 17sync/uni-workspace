import pandas as pd

df=pd.read_csv("titanicdataset.csv")

# 1
print("Survived:", (df["Survived"] == 1).sum())

# 2
print("Died:", (df["Survived"] == 0).sum())

# 3
print("Survival %:", df["Survived"].mean() * 100)

# 4
print("Death %:", (df["Survived"] == 0).mean() * 100)

# 5
print("Males survived:", ((df["Sex"] == "male") & (df["Survived"] == 1)).sum())

# 6
print("Females survived:", ((df["Sex"] == "female") & (df["Survived"] == 1)).sum())

# 7
print("Gender survival rate:")
print(df.groupby("Sex")["Survived"].mean() * 100)

# 8
print("Youngest:", df.loc[df["Age"].idxmin(), ["Name", "Age"]])

# 9
print("Oldest:", df.loc[df["Age"].idxmax(), ["Name", "Age"]])

# 10
print("Average age:", df["Age"].mean())

# 11
print("Older than 50:", df[df["Age"] > 50])

# 12
print("Younger than 18:", df[df["Age"] < 18])

# 13
print("Children:", (df["Age"] < 18).sum())

# 14
print("Under 18 survival rate:",
      df[df["Age"] < 18]["Survived"].mean() * 100)

# 15
print("Highest fare:", df["Fare"].max())

# 16
print("Lowest fare:", df["Fare"].min())

# 17
print("Average fare:", df["Fare"].mean())

# 18
print("Top 10 fares:")
print(df.nlargest(10, "Fare")[["Name", "Fare"]])

# 19 
avg_fare = df["Fare"].mean()
print("Paid more than average:")
print(df[df["Fare"] > avg_fare][["Name", "Fare"]])

# 20
print("Average fare by class:")
print(df.groupby("Pclass")["Fare"].mean())

# 21
print("Survival rate above average fare:",
      df[df["Fare"] > avg_fare]["Survived"].mean() * 100)

