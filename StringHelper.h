#pragma once
<<<<<<< HEAD
#include <string>
=======
>>>>>>> 8983b3930fb6ca799b6d3e0427ff30f459408f58
class StringHelper
{
public:

<<<<<<< HEAD
    /// Брои броят срещания на символа c в стринга.
    static int count(std::string str, const char c);

    ///Брои броят срещания на даден низ в друг низ.
    static int count(std::string str, std::string c);

    ///Брои колко са срещанията на символа с в стринга, в част, в която не е заградена от кавички.
    static int countQ(std::string str, const char c);

    /**
     * Разделя даден низ на масив от поднизове спрямо даден символ.
     * Примерно "Hello World!" ще се раздели на {"Hello", "World!"}
     */

    static std::string* split(std::string str, const char c);

    ///Ако не е зададен символ по който да заделя, то заделя спрямо интервалите в низа.
    static std::string* split(std::string str);

    /**Разделя даден низ на масив от поднизове спрямо даден символ като символите в кавички се игнорират.
     * Примерно <This is "Hello World!"> ще се раздели на {This,is,"Hello World!"}
     */
    static std::string* splitQ(std::string str, const char c);

    ///Ако не е зададен символ по който да заделя, то заделя спрямо интервалите в низа.
    static std::string* splitQ(std::string str);

    /**Премахва срещанията на символа c от най-вкрая на низа, ако има такива.
     *"Dinosauroooooooooo" при указан символ 'o' ще стане "Dinosaur".
     */
    static std::string strip(std::string str, const char c);

    ///Ако не е зададен символ по който да премахва срещанията на символа, то премахва интервалите в низа.
    static std::string strip(std::string str);

    ///Прави същото като strip, но само де премахването се извършва в началото на низа.
    static std::string stripBegin(std::string str, const char c);

    ///Ако не е зададен символ, то премахва интервалите.
    static std::string stripBegin(std::string str);

    ///Обръща низа.
    static std::string reverse(std::string str);

    ///Прави всички букви малки.
    static std::string toLowerCase(std::string str);

    ///Прави всички букви големи.
    static std::string toUpperCase(std::string str);

    /**Ако има множество от последователни интервали, то свежда интервалите до 1.
     * "Hello           World!" ще стане "Hello World!".
     */
    static std::string clearAllConsecutiveSpaces(std::string str);

    /**Ако има множество от последователни интервали, то свежда интервалите до 1, игнорирайки текст в кавички.
     *<echo         "Hello     World!"> ще стане <echo "Hello     World!">.
     */
    static std::string clearAllConsecutiveSpacesQ(std::string str);

    ///Проверява дали всичките символи в низа са букви.
    static bool isAllLetters(std::string str);

    /**Проверява дали всичките символи в низа са цифри.
     * Допуска се рационално число, затова е разрешено най-много 1 път десетичната запетая в низа.
     */
    static bool isNumber(std::string str);

    ///Проверява дали всичките букви са малки.
    static bool isLowercase(std::string str);

    ///Проверява дали всичките букви са големи.
    static bool isUppercase(std::string str);

    //Проверява дали даден символ се съдържа в низа.
    static bool contains(std::string str, const char c);

    //Проверява дали даден низ се съдържа в низа.
    static bool contains(std::string str, std::string c);
=======
private:

>>>>>>> 8983b3930fb6ca799b6d3e0427ff30f459408f58
};

