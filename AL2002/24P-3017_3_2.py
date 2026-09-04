import numpy as np
import matplotlib.pyplot as plt

x=np.array([1, 2, 3, 4, 5])
y1=np.array([2, 4, 6, 8, 10])
y2=np.array([1, 3, 5, 7, 9])

plt.plot(x, y1, label="Line 1")
plt.plot(x, y2, label="Line 2", linestyle=":")

plt.xlabel("X Axis")
plt.ylabel("Y Axis")
plt.title("Line Chart")
plt.legend()
plt.show()

expenses=np.array([20.69, 17.24, 10.34, 51.72])
labels=["Utilities", "Food", "Repairs", "Mortgage"]
colors=["yellow", "green", "orange", "purple"]
explode=[0.1, 0, 0.1, 0.1]

plt.pie(
    expenses,
    labels=labels,
    colors=colors,
    explode=explode,
    autopct="%1.2f%%",
    shadow=True
)

plt.title("Household Expenses")
plt.show()