#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

class Car {
public:
    string brand;
    unsigned long long int fullRotation;

    Car(const char* brand, long int fullRotation) {
        this->brand = strdup(brand);
        this->fullRotation = fullRotation;
    }
};

bool compareCars(Car* a, Car* b) {
    if (a->fullRotation == b->fullRotation) {
        return a->brand < b->brand;
    }
    return a->fullRotation < b->fullRotation;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unsigned int n, d;
    long double p;
    char name[1000];
    cin >> n;
    cin.ignore();

    vector<Car*> cars;
    for(int i = 0; i < n; i++) {
        cin.get(name,1000);
        cin.ignore();
        cin >> p >> d;
        cin.ignore();
        unsigned long long int fullRot = (unsigned long long int)(p*1000)/(d*3.141593*0.0254);
        if(cars.size() < 3) {
            cars.push_back(new Car(name, fullRot));
        }
        else {
            auto maxFullRotCar = max_element(cars.begin(), cars.end(), compareCars);
            if((fullRot < (*maxFullRotCar)->fullRotation) || (fullRot == (*maxFullRotCar)->fullRotation && name < (*maxFullRotCar)->brand)) {
                delete *maxFullRotCar;
                *maxFullRotCar = new Car(name, fullRot);
            }
        }
    }

    sort(cars.begin(), cars.end(), compareCars);

    for(int i = 0; i < 3; i++) {
        cout << cars[i]->brand << '\n' << cars[i]->fullRotation << '\n';
    }

    for(int i = 0; i < 3; i++) {
        delete cars[i];
    }

    return 0;
}