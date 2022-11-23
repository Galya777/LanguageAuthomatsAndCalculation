#include <set>
#include <vector>
#include <fstream>

#include "ALists.h"

/// ��������� ��������� �� ����������.

struct Transition {
    /// �����������, �� ����� �� �������.
    int from;

    /// �����������, ��� ����� ����� �������.
    int to;

    /// ������� �� �����������.
    char letter;

    Transition();
    Transition(int, char, int);

    bool operator== (const Transition);
};

class Authomat
{
public:
    Authomat();
    Authomat(const Authomat&);
    Authomat(int, std::set<int>, std::vector<Transition>, std::set<int>, std::set<int>);
       
    Authomat& operator = (const Authomat&);

    /// ��������� ���� ����� � ���� �� �������� �� ��������.
    static bool isLetter(char);

    /// ����� ����� �� �������.
    std::set<char> getAlphabet();

    int getID() const;
    std::vector<Transition> getTransitions() const;
    std::set<int> getStates() const;
    std::set<int> getBeginningStates() const;
    std::set<int> getEndingStates() const;

    void setID(int);
    void setTransitions(std::vector<Transition>);
    void setStates(std::set<int>);
    void setBeginningStates(std::set<int>);
    void setEndingStates(std::set<int>);

    void addTransition(Transition);
    void addState(int);
    void addBeginningState(int);
    void addEndingState(int);

    void removeTransition(Transition);
    void removeState(int);
    void removeBeginningState(int);
    void removeEndingState(int);

    ///�������, ����� ����������� �������� �������.
    void determinite();

    ///��������� ����� �� �������� ������� ���� � �����.
    bool isFiniteLang() const;

    ///������� ������� � ������� ����.
    void write(std::ofstream&);

    ///���� ������� �� ������� ����.
    void read(std::ifstream&);


private:
    ///���������� ID �� ��������.
    int id;

    ///������ ��������� � ��������.
    std::set<int> states;

    ///������ ������� � ��������.
    std::vector<Transition> transitions;

    ///������ ������� ���������.
    std::set<int> beginningStates;

    ///������ ������ ���������.
    std::set<int> endingStates;
};
