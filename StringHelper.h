#pragma once
<<<<<<< HEAD
#include <string>
=======
>>>>>>> 8983b3930fb6ca799b6d3e0427ff30f459408f58
class StringHelper
{
public:

<<<<<<< HEAD
    /// ���� ����� �������� �� ������� c � �������.
    static int count(std::string str, const char c);

    ///���� ����� �������� �� ����� ��� � ���� ���.
    static int count(std::string str, std::string c);

    ///���� ����� �� ���������� �� ������� � � �������, � ����, � ����� �� � ��������� �� �������.
    static int countQ(std::string str, const char c);

    /**
     * ������� ����� ��� �� ����� �� ��������� ������ ����� ������.
     * �������� "Hello World!" �� �� ������� �� {"Hello", "World!"}
     */

    static std::string* split(std::string str, const char c);

    ///��� �� � ������� ������ �� ����� �� ������, �� ������ ������ ����������� � ����.
    static std::string* split(std::string str);

    /**������� ����� ��� �� ����� �� ��������� ������ ����� ������ ���� ��������� � ������� �� ���������.
     * �������� <This is "Hello World!"> �� �� ������� �� {This,is,"Hello World!"}
     */
    static std::string* splitQ(std::string str, const char c);

    ///��� �� � ������� ������ �� ����� �� ������, �� ������ ������ ����������� � ����.
    static std::string* splitQ(std::string str);

    /**�������� ���������� �� ������� c �� ���-����� �� ����, ��� ��� ������.
     *"Dinosauroooooooooo" ��� ������ ������ 'o' �� ����� "Dinosaur".
     */
    static std::string strip(std::string str, const char c);

    ///��� �� � ������� ������ �� ����� �� �������� ���������� �� �������, �� �������� ����������� � ����.
    static std::string strip(std::string str);

    ///����� ������ ���� strip, �� ���� �� ������������ �� �������� � �������� �� ����.
    static std::string stripBegin(std::string str, const char c);

    ///��� �� � ������� ������, �� �������� �����������.
    static std::string stripBegin(std::string str);

    ///������ ����.
    static std::string reverse(std::string str);

    ///����� ������ ����� �����.
    static std::string toLowerCase(std::string str);

    ///����� ������ ����� ������.
    static std::string toUpperCase(std::string str);

    /**��� ��� ��������� �� �������������� ���������, �� ������ ����������� �� 1.
     * "Hello           World!" �� ����� "Hello World!".
     */
    static std::string clearAllConsecutiveSpaces(std::string str);

    /**��� ��� ��������� �� �������������� ���������, �� ������ ����������� �� 1, ����������� ����� � �������.
     *<echo         "Hello     World!"> �� ����� <echo "Hello     World!">.
     */
    static std::string clearAllConsecutiveSpacesQ(std::string str);

    ///��������� ���� �������� ������� � ���� �� �����.
    static bool isAllLetters(std::string str);

    /**��������� ���� �������� ������� � ���� �� �����.
     * ������� �� ���������� �����, ������ � ��������� ���-����� 1 ��� ����������� ������� � ����.
     */
    static bool isNumber(std::string str);

    ///��������� ���� �������� ����� �� �����.
    static bool isLowercase(std::string str);

    ///��������� ���� �������� ����� �� ������.
    static bool isUppercase(std::string str);

    //��������� ���� ����� ������ �� ������� � ����.
    static bool contains(std::string str, const char c);

    //��������� ���� ����� ��� �� ������� � ����.
    static bool contains(std::string str, std::string c);
=======
private:

>>>>>>> 8983b3930fb6ca799b6d3e0427ff30f459408f58
};

