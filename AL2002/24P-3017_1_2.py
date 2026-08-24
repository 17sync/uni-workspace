list=[2, 46, 6, 12, 81, 5, 22]

def findSecondGreatest(list):
    greatest=float("-inf")          # least possible value
    secondGreatest=float("-inf")

    for number in list:
        if number>greatest:
            greatest=number

    for number in list:
        if number<greatest and number>secondGreatest:
            secondGreatest=number

    return secondGreatest

SecondgreatestNum=findSecondGreatest(list)
print(SecondgreatestNum) 