#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    // declarations
    map<string, vector<string>> villagerColors;
    int choice;

    do{
        cout << "Menu: \n" << "1. Add Villager\n" << "2. Delete Villager\n" << "3. Increase Friendship\n"
            << "4. Decrease Friendship\n" << "5. Search for Villager\n" << "6. Exit\n";
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

        } else if (choice == 3 || choice == 4){

        } else if (choice == 5){

        } else if (choice == 6){

        } else {

        } while ();

        return 0;
    }

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerColors["Audie"] = {"Orange", "Yellow", "Red"};
    villagerColors["Raymond"] = {"Black", "Gray", "White"};
    villagerColors.insert({"Marshal", {"Blue", "White", "Black"}});

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
    for (map<string, vector<string>>::iterator it = villagerColors.begin(); 
                                               it != villagerColors.end(); ++it) {
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
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}