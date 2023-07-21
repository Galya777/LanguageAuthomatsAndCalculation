//
// Created by Aleksandar on 03/06/2019.
//

#ifndef CFG_CFG_H
#define CFG_CFG_H

#include "Grammar.h"

/// Клас който поддържа Функциите от условието на задачата върху контекстно свободни граматики
class CFG
{
private:
    vector<Grammar> grammars;

public:
    /// По дадено ID открива мястото на граматиката във вектора от граматики
    int findIdPlace(int id);

    /// Конкатенира 2 граматики и запазва в паметта новата
    void Concat(const int id1, const int id2);

    /// Обединява 2 граматики и зашазва в паметта новата
    void Union(const int id1,const int id2);

    /// Прилага Звезда на глини на дадена граматика и запазва в паметта новата
    void Iter(const int id);

    /// Проверява дали дадена граматика е в нормална форма на Чомски
    bool Chomsky(const int id);

    /// Шривежда граматика в нормална форма на Чомски и запазва в паметта новата
    void Chomskify(const int id);

    /// Извежда списък от ID на граматиките
    void List();

    /// Отпечатва дадена граматика на екрана
    void Print(const int id);

    /// Отпечатва Grammar is empty, ако езикът е празен или Grammar is not empty в противен случай
    void Empty(const int id);

    /// Проверява дали дадена дума е част от езика и отпечатва YES ако е и NO в противен случай
    void CYK(const int id,const string word);

    /// Добавя ново правило към дадена граматика
    void AddRule(const int id,const Rule rule);

    /// Премахва правило на дадена граматика по зададен пореден номер на правило
    void RemoveRule(const int id,const int n);

    /// Отваря файл и прочита граматиката в него
    void Open(const string file);

    /// Запазва дадена граматика във Файл
    void Save(const int id,const string file);
};


#endif //CFG_CFG_H
