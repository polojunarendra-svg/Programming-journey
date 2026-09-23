# Your Task:
# Create a parent class named Customer.It should have an __init__ constructor that takes name and total_bill.
# It should have a method named calculate_final_bill(self) that prints a generic message: "[Customer Name]'s final bill is $[total_bill]" (No discount for generic customers).
# Create a child class named VIPCustomer that inherits from Customer.
# Override the calculate_final_bill(self) method.VIP customers get a 10% discount on their total_bill.
# Calculate the discounted price and print: "VIP Customer [Name]'s final bill with 10% discount is $[discounted_bill]".
# Create another child class named EmployeeCustomer that inherits from Customer.
# Override the calculate_final_bill(self) method.
# Employees get a flat $20 off their total_bill.
# Calculate the new price and print: "Employee [Name]'s final bill with $20 discount is $[discounted_bill]".
# At the bottom of your script (outside the classes), create an object for each type of customer with a starting bill of $100, call their calculate_final_bill() methods, and print the results.
class Bill:
    money=10
    def calculate_final_bill(self):
        return self.money
class genericcustomer(Bill):
    def calculate_final_bill(self,name,price):
        print(name + ":" + str(price))

class vipcustomer:
    def calculate_final_bill(self,name,price):
        discount = (10/100)*price
        print(name + "Original price is " + str(price) +" And the discount is ", discount,"The total price is",price-discount)

class employe:
    def calculate_final_bill(self,name,price):
        discount=20
        print(name + "Original price is " + str(price) + "And the discount is " ,discount , "The total price is" ,price - discount)
c1 = genericcustomer()
c1.calculate_final_bill("Nani",10000)
b= Bill()
print(b.money)
