#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // initialize the random number generator

    const int BUILDINGS_COUNT = 10; // number of buildings
    const int MAX_FRUITS_COUNT = 3; // maximum number of fruits per building
    const int FRUITS_TYPES_COUNT = 4; // number of fruit types

    char kong = '@'; // symbol for King Kong
    char player = 'X'; // symbol for player
    char building = '#'; // symbol for building
    char fruit_types[FRUITS_TYPES_COUNT] = { '*', '%', '$', '&' }; // fruit types

    int player_position = BUILDINGS_COUNT / 2; // player's starting position
    int kong_position = rand() % BUILDINGS_COUNT; // random position for King Kong
    int fruits[BUILDINGS_COUNT][MAX_FRUITS_COUNT]; // fruits on buildings
    int fruits_count[BUILDINGS_COUNT] = {}; // number of fruits on each building
    int score = 0; // fruit score

    // generate fruits on buildings
    for (int i = 0; i < BUILDINGS_COUNT; i++) {
        int fruits_on_building = rand() % MAX_FRUITS_COUNT;
        for (int j = 0; j < fruits_on_building; j++) {
            fruits[i][j] = rand() % FRUITS_TYPES_COUNT;
        }
        fruits_count[i] = fruits_on_building;
    }

    cout << "Welcome to King Kong Fruit Catch!" << endl;

    while (true) {
        // display game board
        for (int i = 0; i < BUILDINGS_COUNT; i++) {
            // display buildings
            for (int j = 0; j < MAX_FRUITS_COUNT; j++) {
                if (j < fruits_count[i]) {
                    cout << fruit_types[fruits[i][j]];
                }
                else {
                    cout << building;
                }
            }

            // display players and King Kong
            if (i == player_position) {
                cout << player;
            }
            else if (i == kong_position) {
                cout << kong;
            }
            else {
                cout << " ";
            }

            cout << endl;
        }

        if (player_position == kong_position) {
            cout << "King Kong caught you! Game over. Your score: " << score << endl;
            break;
        }

        if (fruits_count[player_position] > 0) {
            score += fruits_count[player_position];
            fruits_count[player_position] = 0;
            cout << "You collected all the fruits on the building! Your score: " << score << endl;
        }

        // move King Kong
        if (kong_position < player_position) {
            kong_position++;
        }
        else if (kong_position > player_position) {
            kong_position--;
        }

        // move player
        cout << "Enter direction (L - left, R - right): ";
        char direction;
        cin >> direction;
        if (direction == 'L') {
            if (player_position > 0) {
                player_position--;
            }
        }
        else if (direction == 'R') {
            if (player_position < BUILDINGS_COUNT - 1) {
                player_position++;
            }
        }
    }

    return 0;
}