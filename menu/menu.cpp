#include <iostream>
#include <vector>

int find(std::vector<int>& arr, int value);  // Function to find a value in the array
void sort(std::vector<int>& arr);          // Function to sort the array

int main(){
    std::vector<int> arr;  // Array to store values
    int choice;           // Variable to store user choice

    do {   // Menu
        std::cout << "Menu:\n";
        std::cout << "1.Add a new value\n";
        std::cout << "2.Remove a value\n";
        std::cout << "3.Sort\n";
        std::cout << "4.Search in array\n";
        std::cout << "5.Exit\n";  // Added newline
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice){   // Switch case for user choice
                case 1:{    // Add
                    int value;
                    std::cout << "Enter value to add: ";
                    std::cin >> value;
                    arr.push_back(value);       // Add value to array
                    break;
                }

                case 2:{        // Remove
                    int value;
                    std::cout << "Enter value to remove: ";
                    std::cin >> value;
                    int index = find(arr, value);
                    if (index != -1){      // Check if value is present in array
                        arr.erase(arr.begin() + index);  // Remove value from array     
                        std::cout << "Value removed.\n"; 
                    } else {
                        std::cout << "Value not found.\n";
                    }
                    break;
                }

                case 3:{           // Sort
                    sort(arr);
                    std::cout << "Array sorted.\n";
                    break;
                }

                case 4:{            // Search
                    int value;
                    std::cout << "Enter value to search: ";
                    std::cin >> value;
                    int index = find(arr, value);
                    if (index != -1){
                        std::cout << "Value found at index " << index << ".\n";
                    } else {
                        std::cout << "Value not found.\n";
                    }
                    break;
                }

                case 5:{            
                    std::cout << "Exiting program.\n";
                    break; // Exit
                }

         } 
    } while (choice != 5);   // Exit when user enters 5
   
    return 0;
}

int find(std::vector<int>& arr, int value){
    for(int i = 0; i < arr.size(); i++){  // Changed to start from 0
        if (arr[i] == value){
            return i;
        }
    }
    return -1;
}

void sort(std::vector<int>& arr){
    bool sort_arr = false;
    int a;
    int i = 0;
    while (!sort_arr){
        if (i < arr.size() - 1 && arr[i] > arr[i + 1]){  // Added boundary check
            a = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = a;
            i = 0;
        } else if(i < arr.size() - 1) {
            i = i + 1;
        } else {
            sort_arr = true;
        }
    }
}