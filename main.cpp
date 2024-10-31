#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

void displayVillagers(const map<string, tuple<int, string, string>>& villagers){
    cout << "Villager info: \n";
    for (const auto& villager: villagers){
        cout << villager.first << " ["
            << get <0>(villager.second) << ", "
            << get <1>(villager.second) << ", "
            << get <2>(villager.second) << "] \n";
        }
}

int main() {
    // declarations
    map<string, tuple< int, string, string >> villagers;
    int choice;
    map<string, vector<string>> villagerColors;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerColors["Audie"] = {"Orange", "Yellow", "Red"};
    villagerColors["Raymond"] = {"Black", "Gray", "White"};
    villagerColors.insert({"Marshal", {"Blue", "White", "Black"}});

    do{
        cout << "Menu: \n"
            << "1. Add Villager\n"
            << "2. Delete Villager\n" 
            << "3. Increase Friendship\n"
            << "4. Decrease Friendship\n" 
            << "5. Search for Villager\n" 
            << "6. Exit\n";
        cin >> choice;

        if (choice == 1){
            string name;
            string species;
            string catchphrase;
            int friendship;
            cout << "Villager Name: ";
            cin >> name;
            cout << "Friendship level: ";
            cin >> friendship;
            cout << "Species: ";
            cin >> species;
            cout << "Catchphrase: ";
            cin.ignore();
            getline(cin, catchphrase);
            villagers[name] = make_tuple(friendship, species, catchphrase);
            cout << name << " added. \n";
        } else if (choice == 2){
            string name;
            cout << "Enter name to delete: ";
            cin >> name;
            if (villagers.erase(name)){
                cout << name << "deleted\n";
            } else {
                cout << name << "doesn't exist\n";
            }
        } else if (choice == 3 || choice == 4){
            string name;
            cout << "Enter name: ";
            cin >> name;
            auto it = villagers.find(name);

            if(it != villagers.end()){
                int& friendship = get<0>(it->second);
                int delta = (choice = 3) ? 1 :-1;

                if ((delta == 1 && friendship < 10) || (delta == -1 && friendship > 0)){
                    friendship += delta;
                    cout << "Friendship is" << (delta == 1 ? "increased" : "decreased\n");
                } else {
                    cout << name << "does not exist\n";
                }
            }

        } else if (choice == 5){
            string name;
            cout << "Name to search: ";
            cin >> name;
            auto it = villagers.find(name);
            if (villagers.count(name) > 0){
                cout << name << "["
                    << get<0>(villagers[name]) << ","
                    << get<1>(villagers[name]) <<  ","
                    << get<2>(villagers[name]) << "]\n";
            } else {
                cout << name << "does not exist";
            }
        } else if (choice == 6){
            cout << "Exit\n";
        } else {
            cout << "Invalid\n";
        }

        displayVillagers(villagers);
    
    } while (choice != 6);

        return 0;

    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villagerColors) {
        cout << pair.first << ": ";
        for (auto color : pair.second)
            cout << color << " ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (auto it= villagerColors.begin(); it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else{
        cout << endl << searchKey << " not found." << endl;
    }

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}
