#ifndef GRAMMAR_H
#define GRAMMAR_H

#include "Rule.h"
#include<vector>

/// Клас който поддържа операции с контекстно свободни граматики
class Grammar
{
private:
    vector<pair<char,vector<Rule>>> rules;
    static int cnt;
    int id;
    int ruleCnt;
    int ogID;
    char startVar;
    vector<char> Vars,Terms;

public:
    Grammar();
    Grammar(const Grammar& other);
    int getID();
    void getNewID();
    /// Добавя ново правило към граматиката
    void addRule(Rule newRule);

    void cpy(const Grammar& other);
    Grammar& operator=(const Grammar& other);

    /// Сортира всички правила на граматиката по тяхното ID
    vector<Rule> getSortedRulesByID();

    /// Занулява ruleCnt
    void resetRuleCnt();

    /// Отпечатва граматика чрез предварително избран поток
    void printGrammar(ostream &os);

    /// Преномерира правилата като се запълват дупки създадени от премахване на правила
    void prenumGrammar();

    /// Премахва правило с пореден номер n
    void removeRule(int n);

    /// Задава нова стартова променлива
    void setStartVar(char startVar);

    /// Връща коя е стартовата променлива на граматиката
    char getStartVar()const;

    /// Премахва единични правила
    void removeSingleRules();

    /// Премахва еднакви правила
    void removeDupeRules();

    /// прилага операция Звезда на Клини
    void iter();

    /// Проверява дали граматиката е в нормална форма на Чомски
    bool checkChomsky();

    /// Привежда граматиката в нормална форма на Чомски и я запазва
    Grammar chomsky();

    /// Проверява дали езикът на граматиката е празен
    bool checkEmpty();

    /// Проверява дали дадена дума принадлежи на езикът на грамтиката чрез CYK алгоритъм
    bool isWordInLang(string word);

    /// Комбинира правилата на две граматики и връща нова граматика, името на стартовата променлива на втората граматика и неизползвана променлива
    pair<pair<Grammar,char>,char> combineRules(const Grammar& other);


};

#endif
