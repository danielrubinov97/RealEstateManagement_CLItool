#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void print(string *buildings, string props[][15], int numberOfBuildings){ //For possible performance increase: add 2D pointer functionality
    cout << endl;
    cout << "------------------" << endl;
    cout << "PRINTING INITIATED" << endl;
    cout << "------------------" << endl;
    cout << endl;
    for(int i = 0; i < numberOfBuildings; i++){
        cout << "For the address: " << buildings[i] << ":" << endl;
        for(int j = 0; j < 15; j++){
            switch (j){
                case 0: 
                    cout << "Block: " << props[i][j] + "," << endl;
                    break;
                case 1: 
                    cout << "Lot: " << props[i][j] + "," << endl;
                    break;
                case 2: 
                    cout << "Lot Size (Area): " << props[i][j] + "," << endl;
                    break;
                case 3: 
                    cout << "Stories: " << props[i][j] + "," << endl;
                    break;
                case 4: 
                    cout << "Residential Units: " << props[i][j] + "," << endl;
                    break;
                case 5: 
                    cout << "Commercial Units: " << props[i][j] + "," << endl;
                    break;
                case 6: 
                    cout << "Total Number of Units: " << props[i][j] + "," << endl;
                    break;
                case 7: 
                    cout << "Total Square Feet: " << props[i][j] + "," << endl;
                    break;
                case 8: 
                    cout << "Zoning Code (1): " << props[i][j] + "," << endl;
                    break;
                case 9:
                    cout << "Zoning Code (2): " << props[i][j] + "," << endl;
                    break;
                case 10: 
                    cout << "FAR Ratio: " << props[i][j] + "," << endl;
                    break;
                case 11: 
                    cout << "Buildable Square Footage: " << props[i][j] + "," << endl;
                    break;
                case 12: 
                    cout << "Air Rights: " << props[i][j] + "," << endl;
                    break;
                case 13: 
                    cout << "Assessment: " << props[i][j] + "," << endl;
                    break;
                case 14: 
                    cout << "Real Estate Taxes: " << props[i][j] << endl;
                    break;  
            }
        }
        cout << "===================" << endl << endl;
    }
    cout << endl;
    cout << "------------------" << endl;
    cout << "PRINTING COMPLETED" << endl;
    cout << "------------------" << endl;
    cout << endl;
    return;
}

void filter_ByZoning(string *buildings, string props[][15], int numberOfBuildings){
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "INITIATING FILTERING PROCESS (by zoning)" << endl;
    cout << "----------------------------------------" << endl;
    cout << endl;
    string response;
    cout << "Would you like to see the building in the zone R7 or R8? ";
    cin >> response;
    int countingOccurances = 0;
    if(response == "R7"){
        for(int i = 0; i < numberOfBuildings; i++){
            if(props[i][8] == "R7"){
                cout << "Building Found"<< endl;
                countingOccurances++;
                cout << "Address of building: " << buildings[i] << endl;
            }
        }
    }
    else if(response == "R8"){
        for(int i = 0; i < numberOfBuildings; i++){
            if(props[i][8] == "R8"){
                cout << countingOccurances + 1 << " Building Found:"<< endl;
                countingOccurances++;
                cout << "Address of Building: " << buildings[i] << endl;
            }
        }
    }
    else{
        cout << "Invalid Response..." << endl;
        return;
    }
    cout << endl;
    cout << "------------------" << endl;
    cout << "FILTERING COMPLETE" << endl;
    cout << "------------------" << endl;
    cout << endl;
    return;
}

int main(){
    cout << "Welcome to Abel's Program!" << endl;
    cout << "DECLARING UP TO 50 BUILDINGS TO BE INPUTTED." << endl;
    string Buildings[50];
    string response;
    int n_actualBuildings = 0;
    ifstream input("Buildings.txt", ios::in);
    cout << "Inputing data from buildings..." << endl;
    cout << "Initalizing Array" << endl;
    for(int i = 0; i < 50; i++){
        Buildings[i] = "";
    }
    char c;
    int i = 0;
    for(string line; getline(input, line);){
            cout << "Added " << i + 1 << " building." << endl;
            Buildings[i] = line;
            i++;
            n_actualBuildings++;
    }
    
    for(int i = 0; i < n_actualBuildings; i++){
        cout << "Building number " << i + 1 << ": " << Buildings[i] << endl;
    }
    input.clear();
    input.close();
    ifstream input2("PropertiesOfBuildings.txt", ios::in);
    string properties[50][15];
    cout << "DECLARING UP TO 15 PROPERTIES PER BUILDING UP TO 50 BUILDINGS TO BE INPUTTED." << endl;
    cout << "Initializing Array..." << endl;
    for(int i = 0; i < 50; i++){
        for(int j = 0; j < 15; j++){
            properties[i][j] = "";
        }
    }
    cout << "Array Initilized!" << endl;
    cout << "Inputing data from properties..." << endl;
    for(int i = 0; i < n_actualBuildings; i++){
        for(int j = 0; j < 15; j++){
            //cout << "In the LOOP" << endl;
            input2 >> properties[i][j];
            //TEST
            //cout << properties[i][j];
        }
    }
    cout << endl;
    cout << endl;
    cout << "-----------------------" << endl;
    cout << "SUCCESS: DATA INPUTTED!" << endl;
    cout << "-----------------------" << endl;
    cout << endl << endl;
    print(Buildings, properties, n_actualBuildings);
    bool ENDED = false;
    int option;
    while(!ENDED){
        cout << "Directions for using this program:" << endl;
        cout << "\t Press 1: Print" << endl;
        cout << "\t Press 2: Add a Building and it's Properties" << endl;
        cout << "\t Press 3: Filter by Zoning" << endl;
        cout << "\t Press 0: EXIT" << endl;
        cout << endl;
        cout << "Please choose the feature you'd like to run: ";
        cin >> option;
        switch (option){
            case 1:
                print(Buildings, properties, n_actualBuildings);
                break;
            case 2:
                cout << "Sorry this feature is in development...." << endl;
                break;
            case 3:
                filter_ByZoning(Buildings, properties, n_actualBuildings);
                break;
            case 0:
                ENDED = true;
                cout << "Thank you for using Abel's Program!" << endl;
                break;
            default:
                cout << "Invalid Input!" << endl << endl; //TO DO: INITATE COUNTER FOR LIMITED TRIES`
        }
    }
    cout << endl;
    cout << "----------------" << endl;
    cout << "PROGRAM COMPLETE" << endl;
    cout << "----------------" << endl;
    cout << endl;
    return 0;
}
