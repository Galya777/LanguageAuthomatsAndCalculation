#include "RegexUtils.h"
<<<<<<< HEAD
#include "Authomat.h"

bool RegexUtils::isValidRegex(std::string regex) {
    int bracketControl = 0;
    for (int i = 0; i < regex.size(); i++) {
        if (regex[i] == '(') bracketControl++;
        if (regex[i] == ')') bracketControl--;
        bool consecutiveOperations = ((regex[i] == '.' || regex[i] == '+') && (regex[i + 1] == '.' || regex[i + 1] == '+' || regex[i + 1] == '*')) || (regex[i] == '*' && regex[i + 1] == '*');
        if (bracketControl < 0 || !(regex[i] == '(' || regex[i] == ')' || regex[i] == '.' || regex[i] == '*' || regex[i] == '+' || Authomat::isLetter(regex[i])) || consecutiveOperations) return false;
    }
    return true;
}

std::string RegexUtils::addPointsWhereAreMissing(std::string regex) {
    std::string newRegex = regex;
    int addedPoints = 0;
    for (int i = 0; i < regex.size(); i++) {
        if ((Authomat::isLetter(regex[i]) && Authomat::isLetter(regex[i + 1])) || (regex[i] == ')' && regex[i + 1] == '(') || (regex[i] == '*' && Authomat::isLetter(regex[i + 1]))) {
            newRegex.insert(newRegex.begin() + i + 1 + addedPoints, '.');
            addedPoints++;
        }
    }
    return newRegex;
}
=======
>>>>>>> 8983b3930fb6ca799b6d3e0427ff30f459408f58
