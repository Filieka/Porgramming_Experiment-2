#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

// Class to represent a friend's location
class Friend {
public:
    int street, avenue;

    Friend(int s, int a) : street(s), avenue(a) {}
};

// Class to represent the meeting point
class MeetingPoint {
public:
    int street, avenue;

    MeetingPoint() : street(0), avenue(0) {}

    void update(int s, int a) {
        street = s;
        avenue = a;
    }
};

// Class to represent the Grid City
class GridCity {
public:
    int streets, avenues;

    GridCity(int s, int a) : streets(s), avenues(a) {}

    MeetingPoint find_best_meeting_point(vector<Friend>& friends) {
        int total_friends = friends.size();
        int min_distance = INT_MAX;
        MeetingPoint meeting_point;

        for (int street = 1; street <= streets; ++street) {
            for (int avenue = 1; avenue <= avenues; ++avenue) {
                int total_distance = 0;
                for (const auto& friend_loc : friends) {
                    total_distance += abs(street - friend_loc.street) + abs(avenue - friend_loc.avenue);
                }

                if (total_distance < min_distance) {
                    min_distance = total_distance;
                    meeting_point.update(street, avenue);
                } else if (total_distance == min_distance) {
                    if (street < meeting_point.street || (street == meeting_point.street && avenue < meeting_point.avenue)) {
                        meeting_point.update(street, avenue);
                    }
                }
            }
        }

        return meeting_point;
    }
};

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int S, A, F;
        cin >> S >> A >> F;
        vector<Friend> friends;
        for (int f = 0; f < F; ++f) {
            int street, avenue;
            cin >> street >> avenue;
            friends.emplace_back(street, avenue);
        }

        GridCity grid_city(S, A);
        MeetingPoint best_meeting_point = grid_city.find_best_meeting_point(friends);
        cout << "(Street: " << best_meeting_point.street << ", Avenue: " << best_meeting_point.avenue << ")" << endl;
    }

    return 0;
}
