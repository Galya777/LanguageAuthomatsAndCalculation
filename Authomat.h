#include <set>
#include <vector>

/// Съхранява преходите на автоматите.

struct Transition {
    /// Състоянието, от което се потегля.
    int from;

    /// Състоянието, към което отива прехода.
    int to;

    /// Буквата на състоянието.
    char letter;

    Transition();
    Transition(int, char, int);

    bool operator== (const Transition);
};

class Authomat
{
public:


private:
    ///Уникалното ID на автомата.
    int id;

    ///Всички състояния в автомата.
    std::set<int> states;

    ///Всички преходи в автомата.
    std::vector<Transition> transitions;

    ///Всички начални състояния.
    std::set<int> beginningStates;

    ///Всички крайни състояния.
    std::set<int> endingStates;
};
