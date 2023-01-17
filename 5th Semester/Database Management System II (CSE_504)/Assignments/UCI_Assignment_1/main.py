import pandas as pd


dataset = pd.read_csv('Cryotherapy.csv')
sex = dataset["sex"]
age = dataset["age"]
time = dataset["Time"]
number_of_warts = dataset["Number_of_Warts"]
type = dataset["Type"]
area = dataset["Area"]

male_yes = 0;
male_no = 0;

print(sex[87])
print(sex)