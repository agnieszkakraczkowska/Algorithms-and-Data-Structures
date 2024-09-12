#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Castle {
    vector<int> connections;
    bool processed = false;
    int distance;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int numOfCastles, numOfConnections, numOfAttackedCastle, numOfDays,castle1, castle2;
    cin >> numOfCastles >> numOfConnections >> numOfAttackedCastle >> numOfDays;
    vector<Castle> castlesVector(numOfCastles);
    for(int i = 0; i < numOfConnections; i++) {
        cin >> castle1 >> castle2;
        castlesVector.at(castle1).connections.push_back(castle2);
        castlesVector.at(castle2).connections.push_back(castle1);
    }

    queue<int> castlesQueue;
    castlesQueue.push(numOfAttackedCastle);
    castlesVector.at(numOfAttackedCastle).processed = true;
    int maxDistance = 0, castlesCounter = 0;

    while(!castlesQueue.empty()) {
        int currentCastle = castlesQueue.front();
        castlesQueue.pop();

        for(int connection : castlesVector.at(currentCastle).connections) {
            if(!castlesVector.at(connection).processed) {
                castlesVector.at(connection).processed = true;
                castlesVector.at(connection).distance = castlesVector.at(currentCastle).distance + 1;
                castlesQueue.push(connection);

                if(castlesVector.at(connection).distance > maxDistance) {
                    maxDistance = castlesVector.at(connection).distance;
                }
                if(2*castlesVector.at(connection).distance <= numOfDays) {
                    castlesCounter++;
                }
            }
        }
    }

    cout << maxDistance << " " << castlesCounter;

    return 0;
}