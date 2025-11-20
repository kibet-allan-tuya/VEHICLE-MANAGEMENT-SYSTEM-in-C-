# VEHICLE-MANAGEMENT-SYSTEM-in-C-
Create a `Vehicle` base class with brand, model, static count, and constructor. Derive `Car`(seats) and `Motorbike`(engineCapacity), override `displayInfo()`. Use global `companyName`, create objects, store via base pointers, use polymorphism. Add `updateModel()`, file write/read, exceptions for invalid seats/engine capacity.


Task 1: Base Class Creation (3 Marks)

Create a base class Vehicle with:

Instance variables: brand, model. (1 Mark)

A static variable count to track the number of vehicles. (1 Mark)

A constructor to initialize data members and update count. (1 Mark)

 

Task 2: Derived Classes with Inheritance (3 Marks)

Create two derived classes from Vehicle:

Car with an additional member seats. (1 Marks)

Motorbike with an additional member engineCapacity. (1 Marks)

Override the displayInfo() method in both classes. (1 Marks)

 

Task 3: Variables and Polymorphism (5 Marks)

 

Define a global variable companyName. (1 Mark)

Use the static variable count to display the number of vehicles created. (1 Mark)

In main():

Create at least two Car objects and two Motorbike objects. (1 Mark)

Store them in an array of Vehicle pointers*. (1 Mark)

Use a loop with polymorphism to call displayInfo() for each object.(1 Mark)

 

Task 4: Local Variables and Model Update (2 Marks)

Implement a method updateModel() in the base class.

Use a local variable to temporarily store the new model. (1 Mark)

Update the instance variable model. (1 Mark)

 

Task 5: File Handling (4 Marks)

Write all vehicle details into a file named vehicles.txt. (2 Marks)

Read the details back from the file and display them on the console. (2 Marks)

 

Task 6: Exception Handling (2 Marks)

Implement error catching with try-catch.

Throw and handle exceptions for:

Invalid number of seats (e.g., negative values). (1 Mark)

Invalid engine capacity (e.g., negative values). (1 Mark)

 

Task 7: Program Quality (2 Marks)

Correctness of program, clarity of output, comments, and proper naming conventions. ( 2 Marks)

 

Task 8: Class Presentation (4 Marks)
