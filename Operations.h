#pragma once
#include "Authomat.h"
class Operations
{
public:
    ///Обединява два автомата.
    static Authomat automatonUnion(const Authomat&, const Authomat&);

    ///Конкатенира два автомата.
    static Authomat automatonConcat(const Authomat&, const Authomat&);

    ///Намира и връща позитивната обвивка на автомат.
    static Authomat automatonUN(const Authomat&);

    ///Намира и връща звездата на Клини за даден автомат.
    static Authomat automatonKleeneStar(const Authomat&);

    ///Преобразува регулярен израз в автомат.
    static Authomat convertRegex(std::string);

    ///Проверява дали дадена дума се разпознава от автомат.
    static bool automatonWordRecognition(Authomat&, std::string);
private:

};

