list1=[12, 7, 4, 2, 1]
list2=[2, 12, 4, 7, 1]

def bubbleSort(list):
    n=len(list)

    for i in range(n):
        swapped=False
        for j in range(0, n-i-1):
            if list[j]>list[j + 1]:
                list[j]=list[j+1] 
                list[j+1]=list[j]
                swapped=True        
        if not swapped:
            break
            
    return list

def checkIdentical(list1, list2):
    n1=len(list1)
    n2=len(list2)

    if n1!=n2:
        return False

    for element in range (n1):
          if list1[element]==list2[element]:
               continue
          else:
               return False
          
    return True

bubbleSort(list1)
bubbleSort(list2)

identical=checkIdentical(list1, list2)
print("Identical") if identical else print ("Not Identical")
          
