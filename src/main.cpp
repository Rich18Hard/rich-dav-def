#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Customer.h"
#include "Table.h"

// Function to prompt and wait for ENTER
void waitForEnter() {
    std::cout << "Press ENTER to continue.";
    std::cin.ignore(); // Clear the input buffer
    std::cin.get();    // Wait for the user to press ENTER
}

// Function to create a random customer
Customer* createRandomCustomer(int number) {
    int emotion = rand() % 10 + 1;  // Random emotion between 1 and 10
    int type = rand() % 3;

    if (type == 0) {
        return new ImpatientCustomer(number, emotion);
    } else if (type == 1) {
        return new PatientCustomer(number, emotion);
    } else {
        return new LoyalCustomer(number, emotion);
    }
}

int main() {
    const int maxCustomers = 4;
    const int numTables = 4;

    std::vector<Table> tables;
    for (int i = 1; i <= numTables; ++i) {
        tables.push_back(Table(i));
    }

    int currentCustomerNumber = 1;
    int currentCustomersInRestaurant = 0;
    bool gameRunning = true;

    // Initialize random seed
    srand(static_cast<unsigned int>(time(0)));

    while (gameRunning) {
        std::cout << "\nRestaurant Management System\n";

        std::cout << "Status:\n";
        for (const auto& table : tables) {
            std::cout << "Table " << table.getTableNumber() << ": ";

            if (table.hasDirtyPlatesStatus()) {
                std::cout << "Table has dirty plates.\n";
            } else if (!table.getOccupiedStatus()) {
                std::cout << "Empty and available.\n";
            } else {
                Customer* seatedCustomer = table.getSeatedCustomer();
                std::cout  << "[" << seatedCustomer->getPersonality() << "] ";
                if (!table.hasOrderTaken()) {
                    std::cout << "Customer seated, order not taken.\n";
                } else if (!table.isOrderProcessed()) {
                    std::cout << "Order taken, processing.\n";
                } else if (!table.isOrderServed()) {
                    std::cout << "Order processed, waiting to be served.\n";
                } else {
                    std::cout << "Order served, ready to unseat.\n";
                }
            }
        }

        // Display orders available to be served
        std::vector<int> readyTables;
        for (const auto& table : tables) {
            if (table.isOrderProcessed() && !table.isOrderServed()) {
                readyTables.push_back(table.getTableNumber());
            }
        }

        if (!readyTables.empty()) {
            std::cout << "\nOrder(s) available to be served to tables: ";
            for (size_t i = 0; i < readyTables.size(); ++i) {
                std::cout << readyTables[i];
                if (i < readyTables.size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << ".\n";
        }

        std::cout << "\nPick an option:\n";
        std::cout << "1. Assign Customer to Table\n";
        std::cout << "2. Take Order\n";
        std::cout << "3. Simulate Order Processing\n";
        std::cout << "4. Serve Customer\n";
        std::cout << "5. Unseat Customer\n";
        std::cout << "6. Clean Table\n";
        std::cout << "7. Exit\n";
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: { // Assign Customer to Table
            if (currentCustomersInRestaurant >= maxCustomers) {
                std::cout << "Maximum customer capacity reached! Cannot add more customers.\n";
            } else {
                std::cout << "Enter table number to seat the customer (1 to " << numTables << "): ";
                int tableChoice;
                std::cin >> tableChoice;

                if (tableChoice < 1 || tableChoice > numTables) {
                    std::cout << "Invalid table number.\n";
                } else if (tables[tableChoice - 1].getOccupiedStatus()) {
                    std::cout << "Table " << tableChoice << " is already occupied.\n";
                } else if (tables[tableChoice - 1].hasDirtyPlatesStatus()) {
                    std::cout << "Table " << tableChoice << " has dirty plates. Clean it first.\n";
                } else {
                    Customer* newCustomer = createRandomCustomer(currentCustomerNumber++);
                    tables[tableChoice - 1].seatCustomer(newCustomer);
                    currentCustomersInRestaurant++;
                    std::cout << "Customer " << newCustomer->getNumber() << " [" << newCustomer->getPersonality() << "] seated at Table " << tableChoice << ".\n";
                }
            }
            waitForEnter();
            break;
        }
        case 2: {  // Take Order
            std::cout << "Enter table number to take order from (1 to " << numTables << "): ";
            int tableChoice;
            std::cin >> tableChoice;

            if (tableChoice < 1 || tableChoice > numTables) {
                std::cout << "Invalid table number.\n";
            } else if (!tables[tableChoice - 1].getOccupiedStatus()) {
                std::cout << "Table " << tableChoice << " is empty.\n";
            } else if (tables[tableChoice - 1].hasOrderTaken()) {
                std::cout << "Order already taken for Table " << tableChoice << ".\n";
            } else {
                tables[tableChoice - 1].takeOrder();
                std::cout << "Order taken for Table " << tableChoice << ".\n";
            }
            waitForEnter();
            break;
        }
        case 3: {  // Simulate Order Processing
            for (auto& table : tables) {
                if (table.hasOrderTaken() && !table.isOrderProcessed()) {
                    table.processOrder();
                }
            }
            std::cout << "Orders have been processed.\n";
            waitForEnter();
            break;
        }
        case 4: {  // Serve Customer
            std::cout << "Enter table number to serve (1 to " << numTables << "): ";
            int tableChoice;
            std::cin >> tableChoice;

            if (tableChoice < 1 || tableChoice > numTables) {
                std::cout << "Invalid table number.\n";
            } else if (!tables[tableChoice - 1].getOccupiedStatus()) {
                std::cout << "Table " << tableChoice << " is empty.\n";
            } else if (!tables[tableChoice - 1].hasOrderTaken()) {
                std::cout << "No order taken yet for Table " << tableChoice << ".\n";
            } else if (tables[tableChoice - 1].isOrderServed()) {
                std::cout << "Order already served for Table " << tableChoice << ".\n";
            } else {
                tables[tableChoice - 1].serveOrder();
                std::cout << "Order served to Table " << tableChoice << ".\n";
            }
            waitForEnter();
            break;
        }
        case 5: { // Unseat Customer
            std::cout << "Enter table number to unseat customer (1 to " << numTables << "): ";
            int tableChoice;
            std::cin >> tableChoice;

            if (tableChoice < 1 || tableChoice > numTables) {
                std::cout << "Invalid table number.\n";
            } else if (!tables[tableChoice - 1].getOccupiedStatus()) {
                std::cout << "No customer at Table " << tableChoice << ".\n";
            } else if (!tables[tableChoice - 1].isOrderServed()) {
                std::cout << "Customer has not been served yet at Table " << tableChoice << ".\n";
            } else {
                tables[tableChoice - 1].unseatCustomer();
                currentCustomersInRestaurant--; // Decrement the count of seated customers
                std::cout << "Customer unseated from Table " << tableChoice << ".\n";
            }
            waitForEnter();
            break;
        }
        case 6: {  // Clean Table
            std::cout << "Enter table number to clean (1 to " << numTables << "): ";
            int tableChoice;
            std::cin >> tableChoice;

            if (tableChoice < 1 || tableChoice > numTables) {
                std::cout << "Invalid table number.\n";
            } else if (!tables[tableChoice - 1].hasDirtyPlatesStatus()) {
                std::cout << "Table " << tableChoice << " has no dirty plates to clean.\n";
            } else {
                tables[tableChoice - 1].cleanTable();
                std::cout << "Table " << tableChoice << " cleaned.\n";
            }
            waitForEnter();
            break;
        }
        case 7: {  // Exit
            gameRunning = false;
            break;
        }
        default:
            std::cout << "Invalid option. Please try again.\n";
            waitForEnter();
        }
    }

    return 0;
}