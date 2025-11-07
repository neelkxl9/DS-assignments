#include<iostream>
#include<string>
using namespace std;

int main() {
    int servers;
    cout << "Enter number of servers: ";
    cin >> servers;

    int hash_servers[servers];
    for (int i = 0; i < servers; i++) {
        hash_servers[i] = 0; 
    }

    int req;
    cout << "Enter number of requests: ";
    cin >> req;

    string ip;
    int val[req];

    for(int i = 0; i < req; i++) {
        cout << "Enter IP address: ";
        cin >> ip;
        int lastDot = ip.find_last_of('.');
        string lastPart = ip.substr(lastDot + 1);
        val[i] = stoi(lastPart);
    }

    int hash_val;
    for(int j = 0; j < req; j++) {
        hash_val = val[j] % servers;  
        int original_hash = hash_val;
        while(hash_servers[hash_val] != 0) {
            hash_val = (hash_val + 1) % servers;
            if (hash_val == original_hash) {
                cout << "Hash table is full, cannot insert value " << val[j] << endl;
                break;
            }
        }
        if (hash_servers[hash_val] == 0) {
            hash_servers[hash_val] = val[j];
        }
    }

    cout << "\nHash table:" << endl;
    for(int k = 0; k < servers; k++) {
        cout << "Server " << k << ": " << hash_servers[k] << endl;
    }
    
    return 0;
}
