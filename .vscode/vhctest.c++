#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

// Task 3: Global variable
string companyName = "AutoMotive Corp";

// Task 1: Base Class Vehicle
class Vehicle
{
protected:
    string brand;     // Instance variable
    string model;     // Instance variable
    static int count; // Static variable to track number of vehicles

public:
    // Constructor to initialize data members and update count
    Vehicle(string b, string m) : brand(b), model(m)
    {
        count++;
    }

    // Virtual destructor for proper cleanup
    virtual ~Vehicle()
    {
        count--;
    }

    // Task 4: Method to update model
    void updateModel(string newModel)
    {
        string tempModel = newModel; // Local variable
        model = tempModel;           // Update instance variable
        cout << "Model updated to: " << model << endl;
    }

    // Virtual method for polymorphism
    virtual void displayInfo()
    {
        cout << "Brand: " << brand << ", Model: " << model;
    }

    // Static method to get vehicle count
    static int getCount()
    {
        return count;
    }

    // Method to write vehicle info to file
    virtual void writeToFile(ofstream &outFile)
    {
        outFile << "Brand: " << brand << ", Model: " << model;
    }

    // Getters
    string getBrand() const { return brand; }
    string getModel() const { return model; }
};

// Initialize static variable
int Vehicle::count = 0;

// Task 2: Derived Class Car
class Car : public Vehicle
{
private:
    int seats; // Additional member

public:
    // Constructor with exception handling for invalid seats
    Car(string b, string m, int s) : Vehicle(b, m)
    {
        // Task 6: Exception handling for invalid seats
        if (s <= 0)
        {
            throw invalid_argument("Error: Number of seats cannot be negative or zero!");
        }
        seats = s;
    }

    // Override displayInfo method
    void displayInfo() override
    {
        cout << "Car - ";
        Vehicle::displayInfo();
        cout << ", Seats: " << seats << endl;
    }

    // Override writeToFile method
    void writeToFile(ofstream &outFile) override
    {
        outFile << "Car - ";
        Vehicle::writeToFile(outFile);
        outFile << ", Seats: " << seats << endl;
    }

    int getSeats() const { return seats; }
};

// Task 2: Derived Class Motorbike
class Motorbike : public Vehicle
{
private:
    int engineCapacity; // Additional member (in cc)

public:
    // Constructor with exception handling for invalid engine capacity
    Motorbike(string b, string m, int ec) : Vehicle(b, m)
    {
        // Task 6: Exception handling for invalid engine capacity
        if (ec <= 0)
        {
            throw invalid_argument("Error: Engine capacity cannot be negative or zero!");
        }
        engineCapacity = ec;
    }

    // Override displayInfo method
    void displayInfo() override
    {
        cout << "Motorbike - ";
        Vehicle::displayInfo();
        cout << ", Engine Capacity: " << engineCapacity << "cc" << endl;
    }

    // Override writeToFile method
    void writeToFile(ofstream &outFile) override
    {
        outFile << "Motorbike - ";
        Vehicle::writeToFile(outFile);
        outFile << ", Engine Capacity: " << engineCapacity << "cc" << endl;
    }

    int getEngineCapacity() const { return engineCapacity; }
};

// Task 5: Function to write vehicle details to file
void writeVehiclesToFile(Vehicle *vehicles[], int size)
{
    ofstream outFile("vehicles.txt");

    if (!outFile)
    {
        cerr << "Error: Unable to open file for writing!" << endl;
        return;
    }

    outFile << "=== Vehicle Management System ===" << endl;
    outFile << "Company: " << companyName << endl;
    outFile << "Total Vehicles: " << Vehicle::getCount() << endl;
    outFile << "=================================" << endl
            << endl;

    for (int i = 0; i < size; i++)
    {
        vehicles[i]->writeToFile(outFile);
    }

    outFile.close();
    cout << "\nVehicle details successfully written to vehicles.txt" << endl;
}

// Task 5: Function to read vehicle details from file
void readVehiclesFromFile()
{
    ifstream inFile("vehicles.txt");

    if (!inFile)
    {
        cerr << "Error: Unable to open file for reading!" << endl;
        return;
    }

    cout << "\n=== Reading from vehicles.txt ===" << endl;
    string line;
    while (getline(inFile, line))
    {
        cout << line << endl;
    }

    inFile.close();
}

/*int main() {
    cout << "=== Vehicle Management System ===" << endl;
    cout << "Company: " << companyName << endl << endl;

    // Array to store Vehicle pointers (Task 3)
    const int ARRAY_SIZE = 4;
    Vehicle* vehicles[ARRAY_SIZE];

    try {
        // Task 3: Create Car objects with exception handling
        cout << "Creating vehicles..." << endl;
        vehicles[0] = new Car("Toyota", "Camry", 5);
        vehicles[1] = new Car("Honda", "Civic", 5);

        // Create Motorbike objects
        vehicles[2] = new Motorbike("Yamaha", "YZF-R15", 155);
        vehicles[3] = new Motorbike("Kawasaki", "Ninja 300", 296);

        cout << "All vehicles created successfully!\n" << endl;

        // Task 3: Display vehicle count using static variable
        cout << "Total vehicles created: " << Vehicle::getCount() << endl << endl;

        // Task 3: Use polymorphism to display all vehicle info
        cout << "=== Vehicle Information ===" << endl;
        for (int i = 0; i < ARRAY_SIZE; i++) {
            vehicles[i]->displayInfo();
        }

        // Task 4: Demonstrate updateModel method
        cout << "\n=== Updating Model ===" << endl;
        vehicles[0]->updateModel("Camry 2024");

        // Task 5: Write to file
        writeVehiclesToFile(vehicles, ARRAY_SIZE);

        // Task 5: Read from file
        readVehiclesFromFile();

        // Demonstrate exception handling with invalid data
        cout << "\n=== Testing Exception Handling ===" << endl;
        cout << "Attempting to create a car with -3 seats..." << endl;

        try {
            Car* invalidCar = new Car("Ford", "Focus", -3);
            delete invalidCar;
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }

        cout << "Attempting to create a motorbike with -500cc engine..." << endl;
        try {
            Motorbike* invalidBike = new Motorbike("Suzuki", "GSX", -500);
            delete invalidBike;
        } catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }

        // Clean up memory
        for (int i = 0; i < ARRAY_SIZE; i++) {
            delete vehicles[i];
        }

        cout << "\n=== Program Completed Successfully ===" << endl;
        cout << "Remaining vehicles: " << Vehicle::getCount() << endl;

    } catch (const exception& e) {
        // Catch any other exceptions
        cerr << "Unexpected error: " << e.what() << endl;

        // Clean up allocated memory in case of exception
        for (int i = 0; i < ARRAY_SIZE; i++) {
            if (vehicles[i] != nullptr) {
                delete vehicles[i];
            }
        }
        return 1;
    }

    return 0;
}*/

int main()
{
    const int ARRAY_SIZE = 10;                 // max number of vehicles
    Vehicle *vehicles[ARRAY_SIZE] = {nullptr}; // initialize all to nullptr

    char option;

    do
    {
        // Display menu
        cout << "\n=== Vehicle Management System ===\n";
        cout << "Company: " << companyName << endl
             << endl;
        cout << "A - Add vehicle\n";
        cout << "D - Display all vehicles\n";
        cout << "U - Update a vehicle model\n";
        cout << "W - Write vehicles to file\n";
        cout << "R - Read vehicles from file\n";
        cout << "Q - Quit\n";
        cout << "Enter option: ";
        cin >> option;
        cin.ignore(); // remove leftover newline

        switch (option)
        {
        case 'A':
        case 'a':
        {
            // Find first empty slot
            int index = -1;
            for (int i = 0; i < ARRAY_SIZE; i++)
            {
                if (vehicles[i] == nullptr)
                {
                    index = i;
                    break;
                }
            }

            if (index == -1)
            {
                cout << "Vehicle list is full!\n";
                break;
            }

            cout << "Enter vehicle type (1 = Car, 2 = Motorbike): ";
            int type;
            cin >> type;
            cin.ignore();

            if (type == 1)
            {
                string make, model;
                int seats;
                cout << "Enter make: ";
                getline(cin, make);
                cout << "Enter model: ";
                getline(cin, model);
                cout << "Enter seats: ";
                cin >> seats;
                cin.ignore();

                try
                {
                    vehicles[index] = new Car(make, model, seats);
                    cout << "Car added successfully!\n";
                }
                catch (const invalid_argument &e)
                {
                    cout << e.what() << endl;
                }
            }
            else if (type == 2)
            {
                string make, model;
                int cc;
                cout << "Enter make: ";
                getline(cin, make);
                cout << "Enter model: ";
                getline(cin, model);
                cout << "Enter engine CC: ";
                cin >> cc;
                cin.ignore();

                try
                {
                    vehicles[index] = new Motorbike(make, model, cc);
                    cout << "Motorbike added successfully!\n";
                }
                catch (const invalid_argument &e)
                {
                    cout << e.what() << endl;
                }
            }
            else
            {
                cout << "Invalid vehicle type.\n";
            }
            break;
        }

        case 'D':
        case 'd':
            if (Vehicle::getCount() == 0)
            {
                cout << "No vehicles to display.\n";
            }
            else
            {
                cout << "\n=== Vehicle Information ===\n";
                for (int i = 0; i < ARRAY_SIZE; i++)
                {
                    if (vehicles[i] != nullptr)
                    {
                        vehicles[i]->displayInfo();
                    }
                }
            }
            break;

        case 'U':
        case 'u':
            if (Vehicle::getCount() == 0)
            {
                cout << "No vehicles to update.\n";
            }
            else
            {
                cout << "\nSelect vehicle number to update: \n";
                int displayIndex = 1;
                int mapping[ARRAY_SIZE]; // maps displayed numbers to array indices
                for (int i = 0; i < ARRAY_SIZE; i++)
                {
                    if (vehicles[i] != nullptr)
                    {
                        cout << displayIndex << ". ";
                        vehicles[i]->displayInfo();
                        mapping[displayIndex++] = i;
                    }
                }

                int choice;
                cin >> choice;
                cin.ignore();

                if (choice < 1 || choice >= displayIndex)
                {
                    cout << "Invalid choice.\n";
                }
                else
                {
                    string newModel;
                    cout << "Enter new model: ";
                    getline(cin, newModel);
                    vehicles[mapping[choice]]->updateModel(newModel);
                    cout << "Model updated successfully!\n";
                }
            }
            break;

        case 'W':
        case 'w':
            if (Vehicle::getCount() == 0)
            {
                cout << "No vehicles to write.\n";
            }
            else
            {
                writeVehiclesToFile(vehicles, ARRAY_SIZE);
                cout << "Vehicles written to file.\n";
            }
            break;

        case 'R':
        case 'r':
            readVehiclesFromFile();
            break;

        case 'Q':
        case 'q':
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid option. Try again.\n";
        }

    } while (option != 'Q' && option != 'q');

    // Clean up memory
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        delete vehicles[i];
    }
}
