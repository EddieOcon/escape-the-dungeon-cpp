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
#include <cctype>

using namespace std;

// Utility: clear cin errors and discard rest of line
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Utility: ask for an integer in [lo, hi], with validation
int askIntInRange(const string& prompt, int lo, int hi) {
    int choice;
    while (true) {
        cout << prompt;
        if (cin >> choice && choice >= lo && choice <= hi) {
            clearInput();
            return choice;
        }
        cout << "Invalid input. Please enter a number from " << lo << " to " << hi << ".\n";
        clearInput();
    }
}

// Utility: ask for Y/N response, with validation
bool askYesNo(const string& prompt) {
    while (true) {
        cout << prompt << " (y/n): ";
        string s; getline(cin, s);
        if (s.size()) {
            char c = tolower(static_cast<unsigned char>(s[0]));
            if (c == 'y') return true;
            if (c == 'n') return false;
        }
        cout << "Please type 'y' or 'n'.\n";
    }
}

int main() {
    // === Introduction and Storyline ===
    cout << "==============================\n";
    cout << "   Escape the Dungeon (C++)\n";
    cout << "==============================\n\n";

    cout << "You wake on cold stone in a lightless cell.\n";
    cout << "Somewhere beyond the door, boots patrol the corridor.\n";
    cout << "Your mission: find a way out.\n\n";

    // Simple state flags the player’s choices will toggle
    bool hasTorch = false;
    bool madeNoise = false;
    bool foundVent = false;

    // === Decision Point #1 (Nested if-else + logical operators) ===
    cout << "You feel around and find:\n";
    cout << "  1) A loose torch bracket on the wall.\n";
    cout << "  2) A rickety stool under the tiny window.\n";
    cout << "  3) Bang on the door and shout for help.\n";
    int first = askIntInRange("Choose (1-3): ", 1, 3);

    if (first == 1) {
        hasTorch = true; // torch is useful later
        cout << "\nThe bracket comes free—sparks kiss the oil. You have a lit torch.\n";
        // Nested branch based on a second decision
        bool inspect = askYesNo("Use the torchlight to inspect the ceiling?");
        if (inspect) {
            foundVent = true;
            cout << "You spot a narrow ventilation grate—loose, but reachable.\n";
        } else {
            cout << "You keep the flame low to avoid notice.\n";
        }
    } else if (first == 2) {
        cout << "\nYou climb the stool and peer out. A guard passes every minute.\n";
        // Nested if with logical operator combining states
        bool whisper = askYesNo("Do you whisper to test if the guard hears you?");
        if (whisper) {
            madeNoise = true;
            cout << "Your whisper echoes more than expected. Footsteps pause… then resume.\n";
        } else {
            cout << "You stay quiet; the guard continues without noticing.\n";
        }
    } else {
        madeNoise = true;
        cout << "\nYou pound the door. The sound travels like thunder.\n";
        cout << "Distant voices answer—definitely not friendly.\n";
    }

    // === Transition based on combined conditions (logical operators) ===
    // If player found the vent (maybe thanks to torch), they can take a safer path.
    // Otherwise, they face the corridor/guard path.
    if (foundVent && hasTorch && !madeNoise) {
        cout << "\nYou pry open the vent using the hot bracket. A tight crawl leads to a junction.\n";
        cout << "Two grates ahead leak faint air:\n";
        cout << "  1) Left: cool air and dripping water.\n";
        cout << "  2) Right: warm air and faint voices.\n";
        int vent = askIntInRange("Choose (1-2): ", 1, 2);

        if (vent == 1) {
            // WIN branch: smart, quiet, prepared
            cout << "\nYou follow the cool air to an old cistern chamber. A rusted grate gives way.\n";
            cout << "Moonlight spills in—an outlet to the river beyond. You slip into freedom.\n";
            cout << "\n*** YOU ESCAPED! (Quiet, careful route) ***\n";
            return 0;
        } else {
            // Nested else: riskier vent path -> mini-lose
            cout << "\nYou crawl toward the warmth. The grate opens above a kitchen hearth.\n";
            cout << "Cooks spot you instantly and raise the alarm.\n";
            cout << "*** CAUGHT! (Too close to the kitchen) ***\n";
            return 0;
        }

    } else {
        // === Corridor Route: MAJOR DECISION handled by switch ===
        cout << "\nYou choose the corridor route. The cell door yields with a squeal.\n";
        cout << "A single guard rounds the corner, surprised to see you.\n";
        cout << "What do you do?\n";
        cout << "  1) Rush and disarm the guard.\n";
        cout << "  2) Distract and slip past.\n";
        cout << "  3) Bluff: claim you're a new recruit on orders.\n";
        int tactic = askIntInRange("Choose (1-3): ", 1, 3);

        // Switch statement (major decision point)
        switch (tactic) {
            case 1: {
                // Use logical operator with earlier choices to influence outcome
                // If the player made noise earlier, guard is alert → harder outcome.
                if (!madeNoise && hasTorch) {
                    cout << "\nYou feint with the torch, then sweep the leg. The guard collapses—unconscious.\n";
                    cout << "You grab his keys and sprint to the outer gate. It opens to the night.\n";
                    cout << "\n*** YOU ESCAPED! (Bold and prepared) ***\n";
                } else if (!madeNoise) {
                    cout << "\nYou lunge and grapple. It’s messy, but you prevail.\n";
                    cout << "Bruised, you limp through an unsecured postern door.\n";
                    cout << "\n*** YOU ESCAPED! (Barely) ***\n";
                } else {
                    cout << "\nThe guard was already alert from the noise. He parries and calls for help.\n";
                    cout << "*** CAUGHT! (Reinforcements arrive) ***\n";
                }
                break;
            }
            case 2: {
                // Distraction success depends on whether you made noise (guards wary)
                if (!madeNoise) {
                    cout << "\nYou toss the stool; it clatters down a side hall. The guard pursues the sound.\n";
                    cout << "You slip through a supply gate and out into the wet night.\n";
                    cout << "\n*** YOU ESCAPED! (Clean distraction) ***\n";
                } else {
                    cout << "\nAlready suspicious, the guard ignores the distraction and spots you.\n";
                    cout << "*** CAUGHT! (Distraction failed) ***\n";
                }
                break;
            }
            case 3: {
                // Bluff: better odds if you didn’t make noise AND you have the torch (as a “signal lamp” prop)
                if (!madeNoise && hasTorch) {
                    cout << "\nYou flash the torch and bark orders with confidence.\n";
                    cout << "The guard hesitates, then salutes and unlocks the main gate for you.\n";
                    cout << "\n*** YOU ESCAPED! (Perfect bluff) ***\n";
                } else if (!madeNoise) {
                    cout << "\nYour story almost works, but the guard asks for a token you don’t have.\n";
                    cout << "He escorts you to the captain…\n";
                    cout << "*** CAUGHT! (Bluff collapsed) ***\n";
                } else {
                    cout << "\nYour earlier shouting gave you away. The guard laughs and shackles you.\n";
                    cout << "*** CAUGHT! (Too much noise) ***\n";
                }
                break;
            }
            default:
                // Should never hit due to validation, but included for safety/best practice
                cout << "\nIndecision seals your fate as more guards arrive.\n";
                cout << "*** CAUGHT! ***\n";
        }
    }

    return 0;
}
