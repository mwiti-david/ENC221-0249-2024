#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


class Reading {
private:
    string type;
    double staffReading;
    string stationName;
    double RL;

public:
    Reading(string t, double reading, string station) {
        type = t;
        staffReading = reading;
        stationName = station;
        RL = 0.0;
    }

    string getType() { return type; }
    double getStaffReading() { return staffReading; }
    string getStationName() { return stationName; }
    double getRL() { return RL; }

    void setRL(double reducedLevel) {
        RL = reducedLevel;
    }

    void display() {
        cout << "Station: " << stationName 
             << " | Type: " << type 
             << " | Reading: " << staffReading 
             << " | RL: " << RL << endl;
    }
};


class InstrumentSetup {
private:
    int setupID;
    double HOC;
    vector<Reading> readings;

public:
    InstrumentSetup(int id) {
        setupID = id;
        HOC = 0.0;
    }

    void addReading(Reading r) {
        readings.push_back(r);
    }

    void calculateHOC(double knownRL) {
        for (int i = 0; i < readings.size(); i++) {
            if (readings[i].getType() == "BS") {
                HOC = knownRL + readings[i].getStaffReading();
                cout << "HOC for Setup " << setupID << ": " << HOC << endl;
                break;
            }
        }
    }

    void calculateRLs() {
        for (int i = 0; i < readings.size(); i++) {
            double rl = HOC - readings[i].getStaffReading();
            readings[i].setRL(rl);
        }
    }

    void displaySetup() {
        cout << "\n=== Setup " << setupID << " ===" << endl;
        cout << "HOC: " << HOC << endl;
        cout << "Readings:" << endl;
        for (int i = 0; i < readings.size(); i++) {
            readings[i].display();
        }
    }

    int getSetupID() { return setupID; }
    double getHOC() { return HOC; }
    vector<Reading> getReadings() { return readings; }
    
    double getLastFSLevel() {
        for (int i = readings.size() - 1; i >= 0; i--) {
            if (readings[i].getType() == "FS") {
                return readings[i].getRL();
            }
        }
        return 0.0;
    }
};

class LevellingBook {
private:
    string projectName;
    vector<InstrumentSetup> setups;
    double startingRL;

public:
    LevellingBook(string name, double startRL) {
        projectName = name;
        startingRL = startRL;
    }

    void addSetup(InstrumentSetup setup) {
        setups.push_back(setup);
    }

    void processAllSetups() {
        if (setups.size() == 0) {
            cout << "No setups to process!" << endl;
            return;
        }

        setups[0].calculateHOC(startingRL);
        setups[0].calculateRLs();

        for (int i = 1; i < setups.size(); i++) {
            double prevFS = setups[i-1].getLastFSLevel();
            setups[i].calculateHOC(prevFS);
            setups[i].calculateRLs();
        }
    }

    void displayAll() {
        cout << "\n========================================" << endl;
        cout << "PROJECT: " << projectName << endl;
        cout << "Starting RL: " << startingRL << endl;
        cout << "========================================" << endl;

        for (int i = 0; i < setups.size(); i++) {
            setups[i].displaySetup();
        }

        cout << "\n========================================" << endl;
        cout << "End of Levelling Book" << endl;
        cout << "========================================" << endl;
    }

    void exportToFile(string filename) {
        ofstream file(filename);
        
        if (!file.is_open()) {
            cout << "Error: Could not create file!" << endl;
            return;
        }

        file << "========================================\n";
        file << "PROJECT: " << projectName << "\n";
        file << "Starting RL: " << startingRL << "\n";
        file << "========================================\n\n";

        for (int i = 0; i < setups.size(); i++) {
            InstrumentSetup setup = setups[i];
            file << "=== Setup " << setup.getSetupID() << " ===\n";
            file << "HOC: " << setup.getHOC() << "\n";
            file << "Readings:\n";
            
            vector<Reading> readings = setup.getReadings();
            for (int j = 0; j < readings.size(); j++) {
                file << "Station: " << readings[j].getStationName()
                     << " | Type: " << readings[j].getType()
                     << " | Reading: " << readings[j].getStaffReading()
                     << " | RL: " << readings[j].getRL() << "\n";
            }
            file << "\n";
        }

        file << "========================================\n";
        file << "End of Levelling Book\n";
        file << "========================================\n";

        file.close();
        cout << "\nData exported to " << filename << " successfully!" << endl;
    }
};


int main() {
    cout << "=== Digital Levelling Calculator ===" << endl;
    cout << "Phase 2: Multiple Setups & File Export\n" << endl;

    LevellingBook book("Highway Survey Project", 100.000);

    
    InstrumentSetup setup1(1);
    setup1.addReading(Reading("BS", 1.525, "BM1"));
    setup1.addReading(Reading("IS", 2.105, "A"));
    setup1.addReading(Reading("IS", 1.875, "B"));
    setup1.addReading(Reading("FS", 2.340, "CP1"));
    book.addSetup(setup1);

    
    InstrumentSetup setup2(2);
    setup2.addReading(Reading("BS", 1.200, "CP1"));
    setup2.addReading(Reading("IS", 1.850, "C"));
    setup2.addReading(Reading("IS", 2.100, "D"));
    setup2.addReading(Reading("FS", 1.950, "CP2"));
    book.addSetup(setup2);

    
    InstrumentSetup setup3(3);
    setup3.addReading(Reading("BS", 1.100, "CP2"));
    setup3.addReading(Reading("IS", 1.650, "E"));
    setup3.addReading(Reading("FS", 2.200, "BM2"));
    book.addSetup(setup3);

    book.processAllSetups();
    book.displayAll();
    book.exportToFile("levelling_results.txt");

    return 0;
}