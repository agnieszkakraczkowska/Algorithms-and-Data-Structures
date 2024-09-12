#include <iostream>
using namespace std;

class Place {
public:
    string name;
    int energyNeeded;
    int inputIndex;

    Place() {}

    Place(string name, int energyNeeded, int index) {
        this->name = name;
        this->energyNeeded = energyNeeded;
        this->inputIndex = index;
    }
};

class Heap {
private:
    Place* heapArray;
    int heapCapacity;
    int size;

    void restoreHeap(int parentIndex) {
        int maxIndex = parentIndex;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        if (leftChildIndex < size && ((heapArray[leftChildIndex].energyNeeded > heapArray[maxIndex].energyNeeded)
                                      || (heapArray[leftChildIndex].energyNeeded == heapArray[maxIndex].energyNeeded && heapArray[leftChildIndex].inputIndex < heapArray[maxIndex].inputIndex))) {
            maxIndex = leftChildIndex;
        }

        if (rightChildIndex < size && ((heapArray[rightChildIndex].energyNeeded > heapArray[maxIndex].energyNeeded)
                                       || (heapArray[rightChildIndex].energyNeeded == heapArray[maxIndex].energyNeeded && heapArray[rightChildIndex].inputIndex < heapArray[maxIndex].inputIndex))) {
            maxIndex = rightChildIndex;
        }

        if (maxIndex != parentIndex) {
            swap(heapArray[parentIndex], heapArray[maxIndex]);
            restoreHeap(maxIndex);
        }
    }

public:
    Heap(int capacity) {
        this->heapArray = new Place[capacity];
        this->heapCapacity = capacity;
        this->size = 0;
    }

    ~Heap() {
        delete[] heapArray;
    }

    void addPlaceToHeap(const Place& placeToAdd) {
        int lastIndex = size;
        heapArray[lastIndex] = placeToAdd;
        size++;

        int parentIndex = (lastIndex-1)/2;
        while (lastIndex > 0 && heapArray[parentIndex].energyNeeded < heapArray[lastIndex].energyNeeded) {
            swap(heapArray[parentIndex], heapArray[lastIndex]);
            lastIndex = parentIndex;
            parentIndex = (lastIndex - 1) / 2;
        }
    }

    void removeHeapsRoot(int characterEnergy) {
        while (characterEnergy > 0 && size > 0) {
            if (heapArray[0].energyNeeded <= characterEnergy) {
                cout << heapArray[0].name << " ";
                characterEnergy -= heapArray[0].energyNeeded;
            }

            heapArray[0] = heapArray[size - 1];
            size--;

            restoreHeap(0);
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    string name;
    int numOfPlaces, energyNeeded, characterEnergy;
    cin >> numOfPlaces;
    Heap placesHeap(numOfPlaces);
    for(int i = 0; i < numOfPlaces; i++) {
        cin >> name >> energyNeeded;
        placesHeap.addPlaceToHeap(Place(name, energyNeeded, i));
    }
    cin >> characterEnergy;
    placesHeap.removeHeapsRoot(characterEnergy);

    return 0;
}