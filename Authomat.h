#include <set>
#include <vector>
#include <fstream>

#include "ALists.h"

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
    Authomat();
    Authomat(const Authomat&);
    Authomat(int, std::set<int>, std::vector<Transition>, std::set<int>, std::set<int>);
       
    Authomat& operator = (const Authomat&);

    /// Проверява дали буква е част от азбуката на автомата.
    static bool isLetter(char);

    /// Взима езика на автомат.
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

    ///Мутатор, който детерминира текущият автомат.
    void determinite();

    ///Проверява езика на текущият автомат дали е краен.
    bool isFiniteLang() const;

    ///Записва автомат в бинарен файл.
    void write(std::ofstream&);

    ///Чете автомат от бинарен файл.
    void read(std::ifstream&);


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
