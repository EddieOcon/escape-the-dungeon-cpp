/*
Author: Eddie O'Con
Assignment: escape-the-dungeon-cpp
Description: Implement the following functionality:
Introduction and game storyline.
Game options using nested if-else statements and switch.
Logical correctness in decision-making.
Input validation to handle incorrect inputs.
*/

#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Clear bad input
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Ask for a number in range
int askIntInRange(const string& prompt, int lo, int hi) {
    int choice;
    while (true) {
        cout << prompt;
        if (cin >> choice && choice >= lo && choice <= hi) {
            clearInput();
            return choice;
        }
        cout << "Invalid input. Please enter a number between " << lo << " and " << hi << ".\n";
        clearInput();
    }
}

// Ask for yes/no
bool askYesNo(const string& prompt) {
    while (true) {
        cout << prompt << " (y/n): ";
        string s; getline(cin, s);
        if (s.size()) {
            char c = tolower(s[0]);
            if (c == 'y') return true;
            if (c == 'n') return false;
        }
        cout << "Please type y or n.\n";
    }
}

int main() {
    // Intro
    cout << "==============================\n";
    cout << "   Escape the Dungeon (C++)\n";
    cout << "==============================\n\n";

    cout << "You wake up in a brick cell with pockets of lava.\n";
    cout << "In the corner, you see a small opening.\n";
    cout << "Your mission is to find an escape.\n\n";

    // Flags
    bool hasTorch = false;
    bool madeNoise = false;
    bool hasGrapplingHook = false;

    // First choice
    cout << "You feel around and find:\n";
    cout << " 1) A loose torch bracket on the wall.\n";
    cout << " 2) A rickety stool under the tiny window.\n";
    cout << " 3) Bang on the door and shout for help.\n";
    cout << " 4) A dusty sack in the corner.\n";

    int first = askIntInRange("Choose (1-4): ", 1, 4);

    if (first == 1) {
        hasTorch = true;
        cout << "\nYou free the bracket. You have a lit torch.\n";
    } else if (first == 2) {
        cout << "\nYou climb on the stool and look out the window. A guard passes now and then.\n";
    } else if (first == 3) {
        madeNoise = true;
        cout << "\nYou hit the door and shout. The sound carries down the hall.\n";
    } else { // 4
        hasGrapplingHook = true;
        cout << "\nInside the sack you find a small grappling hook with a short rope.\n";
    }

    // Try small opening
    if (askYesNo("Do you want to try the small opening?")) {
        if (hasGrapplingHook) {
            cout << "\nYou hook the edge, pull hard, and squeeze through the opening.\n";
            cout << "*** YOU ESCAPED! (Grappling hook) ***\n";
            return 0;
        } else if (hasTorch) {
            cout << "\nYou check the opening with the torch. It is too high to reach by hand.\n";
        } else {
            cout << "\nIt is too dark and too high to judge. You back off for now.\n";
        }
    }

    // Corridor path
    cout << "\nYou choose the corridor route. The cell door creaks open.\n";
    cout << "A guard spots you and blocks the way.\n";
    cout << "What do you do?\n";
    cout << " 1) Rush and disarm the guard.\n";
    cout << " 2) Distract and slip past.\n";
    cout << " 3) Bluff and pretend you belong.\n";
    cout << " 4) Use the grappling hook to climb to the rafters.\n";

    int tactic = askIntInRange("Choose (1-4): ", 1, 4);

    switch (tactic) {
        case 1: {
            if (!madeNoise && hasTorch) {
                cout << "\nYou swing the torch and strike fast. The guard falls.\n";
                cout << "*** YOU ESCAPED! (Torch fight) ***\n";
            } else if (!madeNoise) {
                cout << "\nYou fight hard and barely win. Hurt but free, you stumble out.\n";
                cout << "*** YOU ESCAPED! (Fight) ***\n";
            } else {
                cout << "\nThe guard was alert from your noise. He calls for help.\n";
                cout << "*** CAUGHT! ***\n";
            }
            break;
        }
        case 2: {
            if (!madeNoise) {
                cout << "\nYou toss something aside. The guard follows the sound and you slip out.\n";
                cout << "*** YOU ESCAPED! (Distraction) ***\n";
            } else {
                cout << "\nAlready suspicious, the guard ignores the distraction and spots you.\n";
                cout << "You get caught and are surrounded by 3 armed guards with swords,\n";
                cout << "and a dragon stands behind them.\n";
                cout << "*** CAUGHT! ***\n";
            }
            break;
        }
        case 3: {
            if (!madeNoise && hasTorch) {
                cout << "\nYou wave the torch and bluff. The guard believes you and lets you out.\n";
                cout << "*** YOU ESCAPED! (Bluff) ***\n";
            } else if (!madeNoise) {
                cout << "\nYou try to bluff, but the guard doesn’t buy it.\n";
                cout << "*** CAUGHT! ***\n";
            } else {
                cout << "\nThe guard heard your shouting before. He locks you up.\n";
                cout << "*** CAUGHT! ***\n";
            }
            break;
        }
        case 4: {
            if (!hasGrapplingHook) {
                cout << "\nYou don’t have a grappling hook.\n";
                cout << "*** CAUGHT! ***\n";
            } else if (!madeNoise) {
                cout << "\nYou throw the hook, climb up, and move along the rafters.\n";
                cout << "Below, a dragon sleeps in the shadows. You slip past quietly.\n";
                cout << "*** YOU ESCAPED! (Dragon asleep) ***\n";
            } else {
                cout << "\nYou throw the hook, but the guard was alert.\n";
                cout << "You get caught and are surrounded by 3 armed guards with swords,\n";
                cout << "and a dragon stands behind them.\n";
                cout << "*** CAUGHT! ***\n";
            }
            break;
        }
    }

    return 0;
}
