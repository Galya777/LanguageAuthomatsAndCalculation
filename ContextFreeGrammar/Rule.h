#ifndef RULE_H
#define RULE_H

#include<string>
using namespace std;

/// Помощен клас за правила на граматики
class Rule
{
private:
    char name;
    int id;
    string expr;

public:
    Rule();
    Rule(int id, char name, string expr);
    Rule(int id, char name, char expr);
    Rule(const Rule& other);
    Rule& operator=(const Rule& other);
    void cpy(const Rule& other);

    /// Връща лявата страна на правилото
    char getRuleName();

    /// Връща ID на правилото
    int getRuleID();

    /// Задава ново ID на правилото
    void setRuleID(int id);

    /// Задава нова дясна част на правилото
    void setRuleExpr(string expr);

    /// Задава нова лява част на правилото
    void setRuleName(char name);

    /// Връща дясната част на правилото
    string getExpr() const;
};

#endif // RULE_H
