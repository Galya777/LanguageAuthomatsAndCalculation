#pragma once
#include "Authomat.h"
class Operations
{
public:
    ///��������� ��� ��������.
    static Authomat automatonUnion(const Authomat&, const Authomat&);

    ///����������� ��� ��������.
    static Authomat automatonConcat(const Authomat&, const Authomat&);

    ///������ � ����� ����������� ������� �� �������.
    static Authomat automatonUN(const Authomat&);

    ///������ � ����� �������� �� ����� �� ����� �������.
    static Authomat automatonKleeneStar(const Authomat&);

    ///����������� ��������� ����� � �������.
    static Authomat convertRegex(std::string);

    ///��������� ���� ������ ���� �� ���������� �� �������.
    static bool automatonWordRecognition(Authomat&, std::string);
private:

};

