/*

C++ OOP ASSIGNMENT

Record Management System

Create a class for record management with the following functionalities,
1. Add record
2. Delete record
3. Edit record
4. Sort records based on ID
5. Display record

*/


// Naveen Dahiya



#include <bits/stdc++.h>
using namespace std;

class Record {
public:
    int id;
    string data;

    Record(int id, string data) : id(id), data(data) {}
};

class RecordManagementSystem {
private:
    vector<Record> records;
    
    unordered_set<int> checkId; 
    static bool compareRecords(const Record &a, const Record &b) {
        return a.id < b.id;
    }
    
    
public:
    void addRecord(int id, string data) {
        if(checkId.find(id)==checkId.end()){
            checkId.insert(id);
            records.push_back(Record(id, data));
        }else{
            cout<<"Enter ID is already existed try to give another"<<endl;
        }
    }

    void deleteRecord(int id) {
    	if(checkId.find(id)!=checkId.end()){
	    for (auto it = records.begin(); it != records.end(); ) {
		 if (it->id == id) {
		 	it = records.erase(it);
		 } else {
		        ++it;
		 }
	    }
    	}else{
    		cout<<"No record found to delete"<<endl;
    	}
    }

    void editRecord(int id, string newData) {
    	if(checkId.find(id)!=checkId.end()){
    		for (auto &record : records) {
		    if (record.id == id) {
		        record.data = newData;
		        break;
		    }
		}
    	}else{
    		cout<<"No ID exist which you want to edit"<<endl;
    	}
    }

    void sortRecords() {
        sort(records.begin(), records.end(), compareRecords);
    }

    void displayRecords() {
        for (const auto &record : records) {
            cout << "ID: " << record.id << ", Data: " << record.data << endl;
        }
    }
};

int main() {
    RecordManagementSystem rms;
    int id;
    string data;
    char op;

    while (true) {
        cout << "Enter operation (a for add, d for delete, e for edit, s for sort, v for view, q for quit): ";
        cin >> op;

        switch (op) {
            case 'a':
                cout << "Enter record id and data: ";
                cin >> id >> data;
                rms.addRecord(id, data);
                break;
            case 'd':
                cout << "Enter record id to delete: ";
                cin >> id;
                rms.deleteRecord(id);
                break;
            case 'e':
                cout << "Enter record id and new data: ";
                cin >> id >> data;
                rms.editRecord(id, data);
                break;
            case 's':
                rms.sortRecords();
                rms.displayRecords();
                break;
            case 'v':
                rms.displayRecords();
                break;
            case 'q':
                return 0;
            default:
                cout << "Invalid operation!" << endl;
        }
    }

    return 0;
}

