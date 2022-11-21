#include <set>
#include <vector>

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
