#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <limits>

using namespace std;

class Clock {
private:
    int hour, minute, second;
    string period;

public:
    Clock() : hour(0), minute(0), second(0), period("") {}

    void inputTime() {
        input("Hours", hour, 0, 12, "The value of hr must be between 0 and 12");
        input("Minutes", minute, 0, 59, "The value of minutes must be between 0 and 59");
        input("Seconds", second, 0, 59, "The value of seconds must be between 0 and 59");
        inputPeriod();
    }

    void display24HourClock() {
        int hour24 = (period == "AM" && hour == 12) ? 0 : (period == "PM" && hour != 12) ? hour + 12 : hour;
        cout << "24 hour clock time: " << setw(2) << setfill('0') << hour24 << ":"
             << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << endl;
    }

private:
    void input(const string& label, int& value, int minValue, int maxValue, const string& errorMsg) {
        do {
            try {
                cout << "Enter " << label << " (" << minValue << " to " << maxValue << "): ";
                cin >> value;
                if (value < minValue || value > maxValue)
                    throw out_of_range(errorMsg);
                break;
            } catch (const exception& e) {
                cerr << "Invalid input: " << e.what() << ". Please try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (true);
    }

    void inputPeriod() {
        do {
            try {
                cout << "Enter AM or PM: ";
                cin >> period;
                if (period != "AM" && period != "PM")
                    throw invalid_argument("Period must be either AM or PM");
                break;
            } catch (const exception& e) {
                cerr << "Invalid input: " << e.what() << ". Please try again." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (true);
    }
};

int main() {
    Clock clock;
    clock.inputTime();
    clock.display24HourClock();

    return 0;
}
