#include <iostream>
#include <iomanip> // for setprecision
using namespace std;

const int CITIES = 3;
const int MONTHS = 4;

int main() {
    float rainfall[CITIES][MONTHS];
    string cityNames[CITIES] = {"City A", "City B", "City C"};
    string monthNames[MONTHS] = {"Jan", "Feb", "Mar", "Apr"};

    cout << "Enter the rainfall data (in mm):\n";
    for (int i = 0; i < CITIES; i++) {
        cout << "For " << cityNames[i] << ":\n";
        for (int j = 0; j < MONTHS; j++) {
            cout << "  " << monthNames[j] << ": ";
            cin >> rainfall[i][j];
        }
    }

    cout << "\nRainfall Data (mm):\n";
    cout << "City\t";
    for (int j = 0; j < MONTHS; j++) {
        cout << monthNames[j] << "\t";
    }
    cout << "Average\n";

    cout << fixed << setprecision(2); // Show 2 decimal places

    for (int i = 0; i < CITIES; i++) {
        cout << cityNames[i] << "\t";
        float sum = 0;
        for (int j = 0; j < MONTHS; j++) {
            cout << rainfall[i][j] << "\t";
            sum += rainfall[i][j];
        }
        cout << (sum / MONTHS) << endl;
    }

    return 0;
}
