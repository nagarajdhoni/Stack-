#include <iostream>
#include <limits>
using namespace std;

// ANSI color codes for better visibility
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

#define MAX 5 // Maximum stack size

// Template-based stack class
template <class Type>
class Stack
{
    int top;
    Type *arr;

public:
    // Constructor to initialize stack
    Stack() : top(-1)
    {
        arr = new Type[MAX];
    }

    // Destructor to release allocated memory
    ~Stack()
    {
        delete[] arr;
    }

    // Push an element onto the stack
    bool push(Type ele)
    {
        if (top >= MAX - 1)
        {
            cout << YELLOW << "Stack Overflow!" << RESET << endl;
            return false;
        }
        arr[++top] = ele;
        return true;
    }

    // Pop an element from the stack
    Type pop()
    {
        if (top < 0)
        {
            cout << RED << "Stack Underflow!" << RESET << endl;
            return Type(); // Return default value of Type
        }
        return arr[top--];
    }

    // Check if the stack is empty
    bool is_empty() const
    {
        return top < 0;
    }

    // Display stack elements
    void display() const
    {
        if (top < 0)
        {
            cout << YELLOW << "Stack is empty!" << RESET << endl;
        }
        else
        {
            cout << GREEN << "Stack Elements: " << RESET;
            for (int i = 0; i <= top; i++)
            {
                cout << arr[i] << (i < top ? ", " : "\n");
            }
        }
    }

    // Clear the stack
    void clear()
    {
        top = -1;
    }
};

// Function to display the main menu
void showMainMenu()
{
    cout << CYAN << "\n--- Main Menu ---" << RESET << endl;
    cout << "1. int\n2. char\n3. float\n4. double\n5. string\n6. Exit" << endl;
    cout << "Choose an option: ";
}

// Function to display the sub-menu
void showSubMenu()
{
    cout << CYAN << "\n--- Sub-Menu ---" << RESET << endl;
    cout << "1. Push\n2. Pop\n3. Display Stack\n4. Return to Main Menu" << endl;
    cout << "Choose an option: ";
}

// Function to display the menu for existing stack detection
void showExistingStackMenu()
{
    cout << YELLOW << "\n--- Existing Stack Detected ---" << RESET << endl;
    cout << "1. Continue with the old stack\n2. Create a new stack" << endl;
    cout << "Choose an option: ";
}

// Function to handle stack operations
template <class Type>
void handleStack(Stack<Type> &stack)
{
    int option;

    while (true)
    {
        showSubMenu();
        cin >> option;
        Type element;

        switch (option)
        {
        case 1: // Push element
            cout << "Enter element: ";
            cin >> element;
            if (!stack.push(element))
            {
                cout << RED << "Failed to push. Stack is full." << RESET << endl;
            }
            break;

        case 2: // Pop element
            if (stack.is_empty())
            {
                cout << RED << "Failed to pop. Stack is empty." << RESET << endl;
            }
            else
            {
                cout << GREEN << "Popped element: " << stack.pop() << RESET << endl;
            }
            break;

        case 3: // Display stack
            stack.display();
            break;

        case 4: // Return to main menu
            return;

        default:
            cout << RED << "Invalid Option!" << RESET << endl;
        }
    }
}

// Main function
int main()
{
    int option, choice, attempts = 3;
    bool running = true;

    // Creating stacks for different data types
    Stack<int> intStack;
    Stack<char> charStack;
    Stack<float> floatStack;
    Stack<double> doubleStack;
    Stack<string> stringStack;

    // Flags to check stack creation
    bool intStackCreated = false;
    bool charStackCreated = false;
    bool floatStackCreated = false;
    bool doubleStackCreated = false;
    bool stringStackCreated = false;

    while (running)
    {
        showMainMenu();
        cin >> option;

        switch (option)
        {
        case 1: // Handle int stack
            attempts = 3;
            if (intStackCreated)
            {
                showExistingStackMenu();
                cin >> choice;
                if (choice == 2)
                {
                    intStack.clear();
                    cout << GREEN << "New int stack created." << RESET << endl;
                }
            }
            else
            {
                intStackCreated = true;
            }
            cout << GREEN << "Int stack application is ready to use." << RESET << endl;
            handleStack(intStack);
            break;

        case 2: // Handle char stack
            attempts = 3;
            if (charStackCreated)
            {
                showExistingStackMenu();
                cin >> choice;
                if (choice == 2)
                {
                    charStack.clear();
                    cout << GREEN << "New char stack created." << RESET << endl;
                }
            }
            else
            {
                charStackCreated = true;
            }
            cout << GREEN << "Char stack application is ready to use." << RESET << endl;
            handleStack(charStack);
            break;

        case 3: // Handle float stack
            attempts = 3;
            if (floatStackCreated)
            {
                showExistingStackMenu();
                cin >> choice;
                if (choice == 2)
                {
                    floatStack.clear();
                    cout << GREEN << "New float stack created." << RESET << endl;
                }
            }
            else
            {
                floatStackCreated = true;
            }
            cout << GREEN << "Float stack application is ready to use." << RESET << endl;
            handleStack(floatStack);
            break;

        case 4: // Handle double stack
            attempts = 3;
            if (doubleStackCreated)
            {
                showExistingStackMenu();
                cin >> choice;
                if (choice == 2)
                {
                    doubleStack.clear();
                    cout << GREEN << "New double stack created." << RESET << endl;
                }
            }
            else
            {
                doubleStackCreated = true;
            }
            cout << GREEN << "Double stack application is ready to use." << RESET << endl;
            handleStack(doubleStack);
            break;

        case 5: // Handle string stack
            attempts = 3;
            if (stringStackCreated)
            {
                showExistingStackMenu();
                cin >> choice;
                if (choice == 2)
                {
                    stringStack.clear();
                    cout << GREEN << "New string stack created." << RESET << endl;
                }
            }
            else
            {
                stringStackCreated = true;
            }
            cout << GREEN << "String stack application is ready to use." << RESET << endl;
            handleStack(stringStack);
            break;

        case 6: // Exit program
            cout << CYAN << "Exiting program. Goodbye!" << RESET << endl;
            return 0;

        default:
            attempts--;
            cout << RED << "Invalid option! " << RESET;
            if (attempts > 0)
            {
                cout << "Attempts remaining: " << attempts << endl;
            }
            else
            {
                cout << "No attempts left. Exiting program." << endl;
                return 0;
            }
        }
    }

    return 0;
}
