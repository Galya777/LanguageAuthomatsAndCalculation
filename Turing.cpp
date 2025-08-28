#include <iostream>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

enum Direction { LEFT, RIGHT, STAY };

struct Transition {
    char newSymbol;
    Direction move;
    string nextState;
};

// Turing Machine Simulator
class TuringMachine {
private:
    map<pair<string, char>, Transition> transitions;
    string currentState;
    vector<char> tape;
    int head;
    string haltState;

public:
    TuringMachine(string startState, string haltState, string input) {
        this->currentState = startState;
        this->haltState = haltState;
        tape = vector<char>(input.begin(), input.end());
        tape.push_back('_'); // blank symbol
        head = 0;
    }

    void addTransition(string state, char symbol, char newSymbol, Direction move, string nextState) {
        transitions[{state, symbol}] = {newSymbol, move, nextState};
    }

    void run() {
        while (currentState != haltState) {
            char currentSymbol = tape[head];
            auto key = make_pair(currentState, currentSymbol);

            if (transitions.find(key) == transitions.end()) {
                cout << "No transition found. Halting." << endl;
                break;
            }

            Transition t = transitions[key];

            // Write new symbol
            tape[head] = t.newSymbol;

            // Move head
            if (t.move == RIGHT) {
                head++;
                if (head >= tape.size()) tape.push_back('_');
            } else if (t.move == LEFT) {
                if (head > 0) head--;
            }

            // Change state
            currentState = t.nextState;
        }
    }

    void printTape() {
        for (char c : tape) {
            if (c != '_') cout << c;
        }
        cout << endl;
    }
};

int main() {
    // Example: Increment binary number (e.g., 1011 -> 1100)
    TuringMachine tm("q0", "HALT", "1011");

    // Transitions
    tm.addTransition("q0", '1', '1', RIGHT, "q0");
    tm.addTransition("q0", '0', '0', RIGHT, "q0");
    tm.addTransition("q0", '_', '_', LEFT, "q1");

    tm.addTransition("q1", '1', '0', LEFT, "q1");
    tm.addTransition("q1", '0', '1', STAY, "HALT");
    tm.addTransition("q1", '_', '1', STAY, "HALT");

    // Run machine
    tm.run();

    // Print result
    cout << "Result on tape: ";
    tm.printTape();

    return 0;
}
