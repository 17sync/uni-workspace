import math

list=[1, 2, 3, 4 ,5, 6 ,7, 8, 9, 10]

def countEven(list):
    even=0

    for num in list:
        if num%2==0:
            even+=1
    
    return even

def countOdd(list):
    odd=0

    for num in list:
        if num%2!=0:
            odd+=1
    
    return odd

def countPrime(list):
    prime=0

    for num in list:
        if num==1:
            continue
        if num%2==0:
            continue
        elif num==2:
            prime+=1
        elif num<=0:
            continue
        else:
            limit=int(math.sqrt(num)) + 1
            for divisor in range(3, limit, 2):
                if num%divisor == 0:
                    continue 
        prime+=1

    return prime

evenCount=countEven(list)
oddCount=countOdd(list)
primeCount=countPrime(list)

print("Even:", evenCount)
print("Odd:", oddCount)
print("Prime:", primeCount)