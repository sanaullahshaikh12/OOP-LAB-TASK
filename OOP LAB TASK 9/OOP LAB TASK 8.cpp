#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Flight {
private:
    string flightNumber;
    string departure;
    string arrival;
    int capacity;
    unordered_set<string> bookedPassengers;

public:
    Flight(string fn, string dep, string arr, int cap) : flightNumber(fn), departure(dep), arrival(arr), capacity(cap) {}

    bool bookSeat(const string& passengerID) {
        if (bookedPassengers.size() >= capacity) return false;
        return bookedPassengers.insert(passengerID).second;
    }

    bool cancelSeat(const string& passengerID) {
        return bookedPassengers.erase(passengerID) > 0;
    }

    bool upgradeSeat(const string& passengerID) {
        return bookedPassengers.find(passengerID) != bookedPassengers.end();
    }
};

class Passenger {
private:
    string id;
    string name;

public:
    Passenger(string i, string n) : id(i), name(n) {}

    bool requestBooking(Flight& f) {
        return f.bookSeat(id);
    }

    bool requestCancellation(Flight& f) {
        return f.cancelSeat(id);
    }

    bool requestUpgrade(Flight& f) {
        return f.upgradeSeat(id);
    }
};

int main() {
    Flight f("FL123", "NYC", "LAX", 2);
    Passenger p1("1", "Kazim");
    Passenger p2("2", "Vivek");
    Passenger p3("3", "Jitesh");

    p1.requestBooking(f);
    p2.requestBooking(f);
    p3.requestBooking(f);

    cout << p1.requestUpgrade(f) << endl;
    cout << p3.requestCancellation(f) << endl;

    return 0;
}

