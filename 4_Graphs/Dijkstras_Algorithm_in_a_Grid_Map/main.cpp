#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MapField {
public:
    char character;
    vector<int> connections;
    int distance;
    bool processed;

    MapField(char field) {
        this->character = field;
        this->distance = 1000000;
        this->processed = false;
    }

    MapField() {}
};

class Route {
public:
    int distance;
    int monitoredCount;
    int fieldIndex;

    Route(short distance, int monitoredCount, int fieldIndex) {
        this->distance = distance;
        this->monitoredCount = monitoredCount;
        this->fieldIndex = fieldIndex;
    }
};

struct CompareRoutes {
    bool operator()(const Route& a, const Route& b) {
        if (a.distance == b.distance) {
            return a.monitoredCount > b.monitoredCount;
        }
        return a.distance > b.distance;
    }
};

void dijkstraCheckRoute(vector<MapField>& mapVector, int start) {
    priority_queue<Route,vector<Route>,CompareRoutes> mapQueue;
    mapQueue.emplace(0,0,start);
    mapVector.at(start).distance = 0;

    while(!mapQueue.empty()) {
        Route currentRoute = mapQueue.top();
        mapQueue.pop();

        if(mapVector.at(currentRoute.fieldIndex).character == 'X') {
            cout << currentRoute.distance << " " << currentRoute.monitoredCount << '\n';
            return;
        }

        if(!mapVector.at(currentRoute.fieldIndex).processed) {
            mapVector.at(currentRoute.fieldIndex).processed = true;
            for(int connection : mapVector.at(currentRoute.fieldIndex).connections) {
                if(mapVector.at(connection).character != '#') {
                    int currentDistance = currentRoute.distance + 1;
                    int monitoredCount = currentRoute.monitoredCount;
                    if(mapVector.at(connection).character == 'M') {
                        monitoredCount++;
                    }
                    if(currentDistance < mapVector.at(connection).distance) {
                        mapVector.at(connection).distance = currentDistance;
                        mapQueue.emplace(currentDistance,monitoredCount,connection);
                    }
                }
                else {
                    continue;
                }
            }
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, startIndex;
    char character;
    cin >> n >> m;

    if(n == 1 && m == 1) {
        cout << 0 << " " << 0 << '\n';
    }
    else {
        vector<MapField> mapVector(n*m);
        for(int i = 0; i < n*m; i++) {
            cin >> character;
            mapVector.at(i) = MapField(character);
            if(character == 'S') {
                startIndex = i;
            }
            if(i > 0) {
                if(i <= m-1) {
                    mapVector.at(i).connections.push_back(i-1);
                    mapVector.at(i-1).connections.push_back(i);
                }
                else {
                    if(i%m != 0) {
                        mapVector.at(i).connections.push_back(i-1);
                        mapVector.at(i-1).connections.push_back(i);
                        mapVector.at(i).connections.push_back(i-m);
                        mapVector.at(i-m).connections.push_back(i);
                    }
                    else {
                        mapVector.at(i).connections.push_back(i-m);
                        mapVector.at(i-m).connections.push_back(i);
                    }
                }
            }
        }
        dijkstraCheckRoute(mapVector,startIndex);
    }

    return 0;
}