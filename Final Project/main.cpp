/* Note: Make sure to use at least C++14

Bendol, Cherry Ben Jr. R.
Cabral, Ronald Allen
Aquino, Christian
Ariola, Toshihero
Date of Submission: July 22, 2024

*/

#include <iostream>
#include <string>
#include <iomanip>
#include <map>
#include <algorithm> // used to sort menu, search items, etc..
#include <thread>
#include <chrono>
#include <windows.h>

using namespace std;

// Prototype functions
void clearScreen();
void checkout();
void printReceipt();

// Menu Item, struct-> used to group several related variables in 1 place
struct MenuItem {
    string name;
    int price;
};

// Menu Class
class Menu {
public:
    map<int, MenuItem> items;

    Menu() {
        items[1] = {"Fried Chicken", 70};
        items[2] = {"Liempo", 70};
        items[3] = {"Chicken Adobo", 60};
        items[4] = {"Pork Sinigang", 60};
        items[5] = {"Palabok", 50};
        items[6] = {"Chopseuy", 40};
        items[7] = {"Longganisa", 30};
        items[8] = {"One Cup Java Rice", 30};
        items[9] = {"One Cup Plain Rice", 15};
    }

    void displayMenu()
    {
        cout << "|---------------------------------------------|" << endl;
        cout << "|                                             |" << endl;
        cout << "|              Red Cardinal Bistro            |" << endl;
        cout << "|                    RCB                      |" << endl;
        cout << "|                                             |" << endl;
        cout << "|---------------------------------------------|" << endl;
        cout << "| No  |           Item            | Price     |" << endl;
        cout << "|-----|---------------------------|-----------|" << endl;

        for (const auto &item : items) {
            cout << "| " << setw(2) << item.first   // ID number with 2 spaces for alignment
                 << "  | " << setw(25) << left << item.second.name  // Name with fixed width
                 << " | Php " << setw(5) << right << fixed << setprecision(0) << item.second.price  // Price with fixed width
                 << " |" << endl;
        }

        cout << "|---------------------------------------------|" << endl;
        cout << "|                                             |" << endl;
        cout << "|             V -> View Order                 |" << endl;
        cout << "|                                             |" << endl;
        cout << "|             X -> Remove all Order           |" << endl;
        cout << "|                                             |" << endl;
        cout << "|             M -> Main Menu                  |" << endl;
        cout << "|                                             |" << endl;
        cout << "|             Q -> Quit                       |" << endl;
        cout << "|                                             |" << endl;
        cout << "|---------------------------------------------|" << endl;
        cout << "Press the corresponding number to order" << endl;
    }
};

// Order Class
class Order {
public:
    map<string, pair<MenuItem, int>> orderItems;

    void addItem(MenuItem item)
    {
        if (orderItems.find(item.name) != orderItems.end())
        {
            orderItems[item.name].second++;
        }
        else //not needed (okay to delete)
        {
            orderItems[item.name] = make_pair(item, 1);
        }
    }

    void removeItem(string itemName)
    {
        auto it = orderItems.find(itemName);
        if (it != orderItems.end()) {
            if (--it->second.second <= 0) //use cookie analogy
            {
                orderItems.erase(it);
            }
        }
        else
        {
            cout << "Item not found in the order." << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }

    void cancelOrder() {
        orderItems.clear();
    }

    void viewOrder() {
        int total = 0;
        if (orderItems.empty()) {
            cout << "No items in order.\n";
            this_thread::sleep_for(chrono::seconds(1));
            return;
        }

        const int itemWidth = 27;
        const int priceWidth = 8;
        const int totalLabelWidth = 31;

        while (true) {
            clearScreen();

            cout << "|------------------------------------------------|" << endl;
            cout << "|                                                |" << endl;
            cout << "|              Red Cardinal Bistro               |" << endl;
            cout << "|                    RCB                         |" << endl;
            cout << "|                                                |" << endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "|                 Your Order                     |" << endl;
            cout << "|------------------------------------------------|" << endl;

            for (const auto &item : orderItems) {
                cout << "| " << setw(2) << item.second.second << "x "
                     << setw(itemWidth) << left << item.second.first.name
                     << " | Php " << setw(priceWidth) << right << fixed << setprecision(0) << item.second.first.price * item.second.second
                     << " |" << endl;
                total += item.second.first.price * item.second.second;
            }

            cout << "|------------------------------------------------|" << endl;
            cout << "| " << setw(totalLabelWidth) << left << "Total:"
                 << " | Php " << setw(8) << right << fixed << setprecision(0) << total << " |" << endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "|                                                |" << endl;
            cout << "|              B -> Go back                      |" << endl;
            cout << "|              R -> Remove an Order              |" << endl;
            cout << "|              P -> Proceed to checkout          |" << endl;
            cout << "|              Q -> Quit                         |" << endl;
            cout << "|                                                |" << endl;
            cout << "|------------------------------------------------|" << endl;
            cout << "Enter your choice: ";
            char choice;
            cin >> choice;

            if (choice == 'B' || choice == 'b')
            {
                break;
            }
            else if
            (choice == 'R' || choice == 'r')
            {
                removeOrder();
                break;
            }
            else if
            (choice == 'P' || choice == 'p')
            {
                checkout();
                break;
            }
            else if
            (choice == 'Q' || choice == 'q')
            {
                exit(0);
            }
            else
            {
                cout << "Invalid choice. Please try again." << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
        }
    }

    // Function to call removeItem on the current Order object
    void removeOrder()
    {
    string itemName;
    bool validInput = false;

    while (!validInput)
    {
        clearScreen();
        cout << "Enter the name of the item to remove (Press B to Go Back): ";
        cin.ignore();
        getline(cin, itemName);


        if (itemName == "B" || itemName == "b")
        {
            cout << "Exiting item removal process." << endl;
            return;
        }

        // Trim leading and trailing spaces (if needed)
        itemName.erase(0, itemName.find_first_not_of(' '));
        itemName.erase(itemName.find_last_not_of(' ') + 1);

        // Convert item name to lowercase for case-insensitive comparison
        string lowerItemName = toLowerCase(itemName);

        // Check if item is in the list
        auto it = find_if(orderItems.begin(), orderItems.end(), [&](const auto& pair)
        {
            return toLowerCase(pair.first) == lowerItemName;
        });

        if (it != orderItems.end())
        {
            removeItem(it->first);  // Remove the item from the current order
            cout << "Item removed from order." << endl;
            this_thread::sleep_for(chrono::seconds(1));
            viewOrder();
            break; // Exit the loop as the item is successfully removed
        }
        else
        {
            cout << "Item not recognized. Please check the item name and try again." << endl;
            this_thread::sleep_for(chrono::seconds(1));
            viewOrder();
            break; // Exit the function
            cin.ignore(); // Clear newline left in buffer
        }
    }
}


    // Convert string to lowercase for case-insensitive comparison
    string toLowerCase(const string &str)
    {
        string result = str; // creates a copy of the input string and stores it in a new variable
        transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }

    void checkout()
    {
    char choice;
        while (true)
        {
        clearScreen();
        cout << "|------------------------------------------|" << endl;
        cout << "|                                          |" << endl;
        cout << "|              Red Cardinal Bistro         |" << endl;
        cout << "|                   RCB                    |" << endl;
        cout << "|                                          |" << endl;
        cout << "|------------------------------------------|" << endl;
        cout << "|                                          |" << endl;
        cout << "|              Mode of Payment             |" << endl;
        cout << "|                                          |" << endl;
        cout << "|                C -> Cash                 |" << endl;
        cout << "|                G -> Gcash                |" << endl;
        cout << "|                                          |" << endl;
        cout << "|             Press Q to Quit              |" << endl;
        cout << "|          Enter your choice:______        |" << endl;
        cout << "|                                          |" << endl;
        cout << "|------------------------------------------|" << endl;
        cin >> choice;

            if (choice == 'C' || choice == 'c' || choice == 'G' || choice == 'g')
            {
                dineOutIn();
                break;
            }
            else if (choice == 'Q' || choice == 'q')
            {
                cout << "Exiting Program.." << endl;
                exit(0);
            }
            else
            {
                cout << "Invalid key" << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
        }
    }

    void dineOutIn()
    {
    char choice;
        while (true)
        {
        clearScreen();
        cout << "|------------------------------------------|" << endl;
        cout << "|                                          |" << endl;
        cout << "|             Red Cardinal Bistro          |" << endl;
        cout << "|                   RCB                    |" << endl;
        cout << "|                                          |" << endl;
        cout << "|------------------------------------------|" << endl;
        cout << "|                                          |" << endl;
        cout << "|               Dining Option              |" << endl;
        cout << "|                                          |" << endl;
        cout << "|               I -> Dine-In               |" << endl;
        cout << "|               O -> Dine-Out              |" << endl;
        cout << "|                                          |" << endl;
        cout << "|              Press Q to Quit             |" << endl;
        cout << "|                                          |" << endl;
        cout << "|           Enter your choice:______       |" << endl;
        cout << "|                                          |" << endl;
        cout << "|------------------------------------------|" << endl;
        cin >> choice;

            if (choice == 'I' || choice == 'i' || choice == 'O' || choice == 'o')
            {
                printReceipt();
                break;
            }

            else if (choice == 'Q' || choice == 'q')
            {
                cout << "Exiting Program.." << endl;
                exit(0);
            }

            else
            {
                cout << "Invalid key" << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
        }
    }

    void printReceipt() {
        int total = 0;
        if (orderItems.empty())
        {
            cout << "No items in order.\n";
            return;
        }

        const int itemWidth = 27;   // Width for item names
        const int priceWidth = 8;   // Width for price column (including space for "Php")
        const int totalLabelWidth = 31; // Width for the "Total:" label

        clearScreen(); // Optional: Clears the screen before displaying the order

        cout << "|------------------------------------------------|" << endl;
        cout << "|                                                |" << endl;
        cout << "|               Red Cardinal Bistro              |" << endl;
        cout << "|                     RCB                        |" << endl;
        cout << "|                                                |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "|                  Your Order                    |" << endl;
        cout << "|------------------------------------------------|" << endl;

        for (const auto &item : orderItems)
        {
            cout << "| " << setw(2) << item.second.second << "x "
                 << setw(itemWidth) << left << item.second.first.name
                 << " | Php " << setw(priceWidth) << right << fixed << setprecision(0) << item.second.first.price * item.second.second
                 << " |" << endl;
            total += item.second.first.price * item.second.second;
        }

        cout << "|------------------------------------------------|" << endl;
        cout << "| " << setw(totalLabelWidth) << left << "Total:"
             << " | Php " << setw(8) << right << fixed << setprecision(0) << total << " |" << endl;
        cout << "|------------------------------------------------|" << endl;
        cout << "|                                                |" << endl;
        cout << "|                                                |" << endl;
        cout << "|            Thank you for Ordering!             |" << endl;
        cout << "|                                                |" << endl;
        cout << "|                                                |" << endl;
        cout << "|------------------------------------------------|" << endl;

        exit(0);
    }
};

// Customer Class
class Customer
{
private:
    string name;
    Order order;

public:
    void startOrder(Menu &menu)
    {
        char choice;
        while (true) {
            clearScreen();
            cout << "|------------------------------------------|" << endl;
            cout << "|                                          |" << endl;
            cout << "|             Red Cardinal Bistro          |" << endl;
            cout << "|                   RCB                    |" << endl;
            cout << "|                                          |" << endl;
            cout << "|------------------------------------------|" << endl;
            cout << "|                                          |" << endl;
            cout << "|            S -> Start Ordering           |" << endl;
            cout << "|            Q -> Quit                     |" << endl;
            cout << "|                                          |" << endl;
            cout << "|           Enter your choice:_____        |" << endl;
            cout << "|                                          |" << endl;
            cout << "|------------------------------------------|" << endl;

            cin >> choice;

            if (choice == 'S' || choice == 's')
            {
                enterName();
                placeOrder(menu);
                break; // Exit the loop after placing the order
            }

            else if (choice == 'Q' || choice == 'q')
            {
                cout << "Exiting the program..." << endl;
                exit(0);
            }

            else
            {
                cout << "Invalid choice. Please try again." << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
        }
    }

    void enterName() {
        clearScreen();

        cout << "|------------------------------------------|" << endl;
        cout << "|                                          |" << endl;
        cout << "|             Red Cardinal Bistro          |" << endl;
        cout << "|                   RCB                    |" << endl;
        cout << "|                                          |" << endl;
        cout << "|------------------------------------------|" << endl;
        cout << "|                                          |" << endl;
        cout << "|              Enter Name:_____            |" << endl;
        cout << "|                                          |" << endl;
        cout << "|                                          |" << endl;
        cout << "|              Press Q to Quit             |" << endl;
        cout << "|                                          |" << endl;
        cout << "|------------------------------------------|" << endl;
        cin >> name;

        if (name == "Q" || name == "q")
        {
            cout << "Exiting the program..." << endl;
            exit(0);
        }
    }

    void placeOrder(Menu &menu)
    {
        string input;
        bool returnToMainMenu = false;

        while (true)
        {
            clearScreen();
            menu.displayMenu();
            cout << "Enter your choice: ";
            getline(cin, input); // Read the entire line of input

            if (input.empty())
            {
                cout << "Empty input. Please try again." << endl;
                continue;
            }

            // Check if input is a number (ID)
            if (isdigit(input[0]))
            {
                int choice = stoi(input);
                if (choice >= 1 && choice <= 99) { // Adjust the range according to menu
                    if (menu.items.find(choice) != menu.items.end())
                    {
                        order.addItem(menu.items[choice]);
                        cout << "Added: " << menu.items[choice].name << endl;
                        this_thread::sleep_for(chrono::seconds(1));
                    }

                    else
                    {
                        cout << "Invalid choice. Try again." << endl;
                        this_thread::sleep_for(chrono::seconds(1));
                    }
                }

                else
                {
                    cout << "Invalid choice. Try again." << endl;
                    this_thread::sleep_for(chrono::seconds(1));
                }
            }

            else
            {
                char command = toupper(input[0]); // Convert to uppercase for easier comparison
                switch (command)
                {
                    case 'M':
                        returnToMainMenu = true;
                        break;
                    case 'X':
                        order.cancelOrder();
                        cout << "Order cancelled." << endl;
                        this_thread::sleep_for(chrono::seconds(1));
                        break;
                    case 'V':
                        clearScreen();
                        order.viewOrder();
                        cout << "Press Enter to return to the menu...";
                        cin.ignore();
                        cin.get();
                        break;
                    case 'Q':
                        cout << "Exiting the program..." << endl;
                        exit(0);
                    default:
                        cout << "Invalid choice. Try again." << endl;
                        this_thread::sleep_for(chrono::seconds(1));
                }
            }

            if (returnToMainMenu) {
                cout << "Returning to the main menu..." << endl;
                clearScreen();
                break;
            }
        }
    }
};

//CLASS admin
class Admin
{
public:
     void addMenuItem(Menu &menu, const string &name, int price)
     {
         // Determine the next available ID
         int newID = menu.items.empty() ? 1 : menu.items.rbegin()->first + 1;
         menu.items[newID] = {name, price};
         cout << "Food item added successfully with ID " << newID << "!" << endl;
     }

     void removeMenuItem(Menu& menu, int id)
     {
        if (menu.items.find(id) != menu.items.end()) {
            menu.items.erase(id);
            cout << "Menu item removed." << endl;
        } else {
            cout << "Invalid ID, please enter again." << endl;
        }
        this_thread::sleep_for(chrono::seconds(1));
    }

     void changeMenuItemPrice(Menu &menu, int id, int newPrice)
     {
         if (menu.items.find(id) != menu.items.end())
         {
             menu.items[id].price = newPrice;
         }
     }
 };


// Main System Class
class System
{
public:
    void run()
    {
    Menu menu;
    Customer customer;
    Admin admin;

    char choice;
    while (true)
    {
        clearScreen();
        cout << "|------------------------------------------|" << endl;
        cout << "|                                          |" << endl;
        cout << "|             Red Cardinal Bistro          |" << endl;
        cout << "|                   RCB                    |" << endl;
        cout << "|                                          |" << endl;
        cout << "|------------------------------------------|" << endl;
        cout << "|                                          |" << endl;
        cout << "|            C -> Customer View            |" << endl;
        cout << "|            A -> Admin View               |" << endl;
        cout << "|                                          |" << endl;
        cout << "|           Enter your choice:______       |" << endl;
        cout << "|                                          |" << endl;
        cout << "|------------------------------------------|" << endl;
        cin >> choice;

        if (choice == 'C' || choice == 'c')
        {
            customer.startOrder(menu); // Pass menu to startOrder
        }
        else if (choice == 'A' || choice == 'a')
        {
            adminMenu(menu, admin); // Handle admin menu
        }
        else
        {
            cout << "Invalid key" << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
}


private:
void adminMenu(Menu &menu, Admin &admin)
{
    char choice;
    while (true) {
        clearScreen();
        cout << "|------------------------------------------|" << endl;
        cout << "|                                          |" << endl;
        cout << "|            Red Cardinal Bistro           |" << endl;
        cout << "|                   RCB                    |" << endl;
        cout << "|                                          |" << endl;
        cout << "|------------------------------------------|" << endl;
        cout << "|                                          |" << endl;
        cout << "|                Admin View                |" << endl;
        cout << "|                                          |" << endl;
        cout << "|       A -> Add Menu Item                 |" << endl;
        cout << "|       R -> Remove Menu Item              |" << endl;
        cout << "|       C -> Change Menu Item Price        |" << endl;
        cout << "|       M -> Return to Main Menu           |" << endl;
        cout << "|       Q -> Quit                          |" << endl;
        cout << "|                                          |" << endl;
        cout << "|------------------------------------------|" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 'A' || choice == 'a')
        {
            string name;
            int price;
            cout << "Enter food: ";
            cin.ignore(); // Clear newline left in buffer
            getline(cin, name);
            cout << "Enter price: ";
            cin >> price;
            admin.addMenuItem(menu, name, price);
        }

        else if (choice == 'R' || choice == 'r')
        {
            int id;
            cout << "Enter ID of the item to remove: ";
            cin >> id;
            admin.removeMenuItem(menu, id);
        }

        else if (choice == 'C' || choice == 'c')
        {
            int id, newPrice;
            cout << "Enter ID of the item: ";
            cin >> id;
            if (menu.items.find(id) != menu.items.end())
            {
                cout << "Enter new price: ";
                cin >> newPrice;
                admin.changeMenuItemPrice(menu, id, newPrice);
            } else {
                cout << "Invalid ID. Item does not exist.\n";
                this_thread::sleep_for(chrono::seconds(2)); // Add a delay before re-prompting
                continue; // Go back to the start of the loop to prompt again
            }
        }

        else if (choice == 'M' || choice == 'm')
        {
            break; // Return to the main menu
        }

        else if (choice == 'Q' || choice == 'q')
        {
            cout << "Exiting the program..." << endl;
            exit(0);
        }

        else
        {
            cout << "Invalid choice. Please try again.\n";
            this_thread::sleep_for(chrono::seconds(1));
        }
        cout << "Press Enter to continue...";
        cin.ignore(); // Clear newline left in buffer
        cin.get();
    }
}
};

// Clear screen function
void clearScreen() {
    system("cls");
}

// Main function
int main() {
    System system;
    system.run();
    return 0;
}
