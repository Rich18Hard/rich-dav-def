#include <iostream>
#include "Customer.h"
#include "CustomerQueue.h"
#include "Table.h"
#include "Kitchen.h"
#include "Dishwasher.h"
#include "Player.h"
#include "Queue.h"
#include "Order.h"

int main() {
    CustomerQueue customerQueue;
    Kitchen kitchen;
    Dishwasher dishwasher;
    Player player;

    int option;
    bool gameRunning = true;

    while (gameRunning) {
        std::cout << "\nRestaurant Management System\n";
        std::cout << "1. Display Order Status\n";
        std::cout << "2. Assign Customer to Table\n";
        std::cout << "3. Take Order\n";
        std::cout << "4. Serve Customer\n";
        std::cout << "5. Simulate Order Processing\n";
        std::cout << "6. Unseat Customer\n";
        std::cout << "7. Clean Table\n";
        std::cout << "8. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> option;

        switch (option) {
            case 1: {
                std::cout << "Displaying Order Status...\n";
                // Implement logic to display orders and their statuses
                break;
            }

            case 2: {
                // Generate customer and add to queue
                Customer* customer = new Customer(1, 5);  // Example: 1 customer with emotion 5
                customerQueue.enqueueCustomer(customer);
                std::cout << "Customer added to queue.\n";
                break;
            }

            case 3: {
                if (!customerQueue.isQueueEmpty()) {
                    Customer* customer = customerQueue.dequeueCustomer();
                    Table* table = new Table();
                    table->setCustomerCount(customer->getCustomerCount());
                    Order* order = new Order(1);  // Example order
                    table->setOrder(order);
                    kitchen.addOrder(1, order);  // Add order to kitchen
                    std::cout << "Order taken and sent to kitchen.\n";
                } else {
                    std::cout << "No customers in the queue.\n";
                }
                break;
            }

            case 4: {
                std::cout << "Serving customer...\n";
                // Implement logic to serve customer, mark order as served
                break;
            }

            case 5: {
                std::cout << "Simulating Order Processing...\n";
                // Process order in kitchen, serve it
                if (kitchen.getOrder(1) != nullptr) {
                    kitchen.getOrder(1)->serveOrder();
                    std::cout << "Order processed.\n";
                }
                break;
            }

            case 6: {
                std::cout << "Unseating customer...\n";
                // Unseat customer logic
                break;
            }

            case 7: {
                std::cout << "Cleaning table...\n";
                // Clean table logic
                dishwasher.toggle();  // Toggle dishwasher on
                dishwasher.generateMoney();  // Generate money from cleaning
                break;
            }

            case 8: {
                gameRunning = false;
                std::cout << "Exiting...\n";
                break;
            }

            default: {
                std::cout << "Invalid option. Try again.\n";
                break;
            }
        }
    }

    return 0;
}
