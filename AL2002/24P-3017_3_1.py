import numpy as np

a1=np.array([34, 23, 22, 44])
a2=np.array([69, 12, 88, 54])

print(a1+a2)
print(a1*100)
print(a1.reshape(2, 2))
print(a1.astype(float))

seqArray=np.arange(0, 100, 2)
print(seqArray)

SimilarIndexes=np.where(a1==a2)
print(SimilarIndexes)