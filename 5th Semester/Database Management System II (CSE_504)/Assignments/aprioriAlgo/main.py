import dataTable
import aprioriAlgorithm

# for frequency table
# frequencyTable = aprioriAlgorithm.createFrequency(dataTable.table, 2, 2)
# for i in frequencyTable:
#     print(i)

# a = aprioriAlgorithm.getConfidence("3=>1,2",dataTable.table, 2)
#
# print(a)

while True:
    choice = input("1. Frequency Table with support count    2. Confidence    3. Exit   : ")

    if choice == "1":
        minSupportCount = int(input("Minimum Support Count: "))
        length = int(input("Length of the itemList: "))
        frequencyTable = aprioriAlgorithm.createFrequency(dataTable.table, length, minSupportCount)
        for i in frequencyTable:
            print(i)

    elif choice == "2":
        minSupportCount = int(input("Minimum Support Count: "))
        expression = input('Enter an expression in formate, "I1 => I2" or "{I1, I2} => I3" or "I1 => {I3,I4}"  : ')
        print(aprioriAlgorithm.getConfidence(expression, dataTable.table, minSupportCount))
    else:
        break

