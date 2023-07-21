//
// Created by Aleksandar on 20/05/2019.
//

#ifndef CFG_GRAMMARHELPERFUNCTIONS_H
#define CFG_GRAMMARHELPERFUNCTIONS_H

#include<vector>
#include "Rule.h"
using namespace std;

/// Проверява дали символът е променлива
bool isVariable(char k);

/// Проверява дали символът е нове за граматиката
bool checkIfNew(char c,const vector<char> &v);

/// Връща неизползвана променлива
char getFreeVar(int used[]);

/// Ако дясната част на правилото има епсилон променлива, генерира всички нови правила със и без епсилон променливите
void generateAllRulesAfterEpsilon(int x, char newRuleName,string expr, string newExpr, bool hasEpsilon[], vector<Rule> &newRules);

/// Проверява дали правило с дадена лява част има дясна част от 1 променлива
bool hasSingleVar(vector<Rule> rules);

/// Помощна функция за сортиране на правила по лява страна
bool cmpChom(Rule a,Rule b);

/// Помощна функция за сортиране на правила по ID
bool cmp(Rule a, Rule b);

#endif //CFG_GRAMMARHELPERFUNCTIONS_H
