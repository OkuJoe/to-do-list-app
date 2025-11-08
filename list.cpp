#include<iostream>
#include<string>
using namespace std;

/* 
Logic Flow:
1. Display menu options repeatedly until user chooses to exit
2. Add new task - store in array and increment counter
3. View tasks - display all current tasks with proper numbering
4. Delete task - remove specified task and shift remaining tasks
5. Input validation for all user inputs
*/

// Function to display all tasks
void print_tasks(string tasks[], int task_count)
{
    if(task_count == 0)
    {
        cout << "No tasks available!" << endl;
        return;
    }
    
    cout << "_____ " << endl;
    cout << "   YOUR TASKS:" << endl;
    cout << "_____ " << endl;
    
    for(int i = 0; i < task_count; i++)
    {
        cout << " Task " << (i+1) << ": " << tasks[i] << endl;
    }
    cout << "_____ " << endl;
}

// Function to delete a task
void delete_task(string tasks[], int &task_count)
{
    if(task_count == 0)
    {
        cout << "No tasks to delete!" << endl;
        return;
    }
    
    // First show current tasks
    print_tasks(tasks, task_count);
    
    int task_to_delete;
    cout << "Enter task number to delete (1-" << task_count << "): ";
    cin >> task_to_delete;
    
    // Validate input (convert to 0-based indexing)
    task_to_delete--; // Convert to 0-based index
    
    if(task_to_delete < 0 || task_to_delete >= task_count)
    {
        cout << "Invalid task number!" << endl;
        return;
    }
    
    // Shift all tasks after the deleted one to the left
    for(int i = task_to_delete; i < task_count - 1; i++)
    {
        tasks[i] = tasks[i + 1];
    }
    
    task_count--; // Decrease task count
    cout << "Task deleted successfully!" << endl;
}

// Function to add a new task
void add_task(string tasks[], int &task_count)
{
    if(task_count >= 10)
    {
        cout << "Task list is full! Cannot add more tasks." << endl;
        return;
    }
    
    cout << "Enter new task: ";
    cin.ignore(); // Clear input buffer
    getline(cin, tasks[task_count]);
    task_count++;
    cout << "Task added successfully!" << endl;
}

int main()
{
    string tasks[10]; // Array to store tasks
    int task_count = 0; // Counter for number of tasks
    int option = -1;
    
    cout << "Welcome to Your Personal To-Do List!" << endl;
    cout << "=====================================" << endl;
    
    while(option != 0)
    {
        // Display menu
        cout << "\n------- TO DO LIST MENU -------" << endl;
        cout << " 1 ---- Add new task" << endl;
        cout << " 2 ---- View all tasks" << endl;
        cout << " 3 ---- Delete a task" << endl;
        cout << " 0 ---- Exit program" << endl;
        cout << "-------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> option;
        
        switch(option)
        {
            case 1: // Add new task
            {
                add_task(tasks, task_count);
                break;
            }
            
            case 2: // View tasks
            {
                print_tasks(tasks, task_count);
                break;
            }
            
            case 3: // Delete task
            {
                delete_task(tasks, task_count);
                break;
            }
            
            case 0: // Exit
            {
                cout << "Thank you for using To-Do List! Goodbye!" << endl;
                break;
            }
            
            default:
            {
                cout << "Invalid option! Please choose 0-3." << endl;
                break;
            }
        }
    }
    
    return 0;
}