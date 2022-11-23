#include "Commands.h"
<<<<<<< HEAD


bool Commands::openedFile = false;
std::string Commands::openedFilePath;
std::string Commands::fileName;

void Commands::setFileName() {
    int countSlash = StringHelper::count(Commands::openedFilePath, '/');
    int countBackslash = StringHelper::count(Commands::openedFilePath, (char)92);

    if (countSlash == 0 && countBackslash == 0) Commands::fileName = Commands::openedFilePath;
    else if (countSlash > 0) {
        std::string* sepPath = StringHelper::split(openedFilePath, '/');
        Commands::fileName = sepPath[countSlash];
    }
    else if (countBackslash > 0) {
        std::string* sepPath = StringHelper::split(openedFilePath, (char)92);
        Commands::fileName = sepPath[countBackslash];
    }
}

void Commands::open(std::string filePath) {
    if (!openedFile) {
        std::ifstream in(filePath, std::ios::binary | std::ios::in);

        if (!in.is_open()) {
            std::ofstream out(filePath, std::ios::binary | std::ios::out);
            out.close();
            in.open(filePath, std::ios::binary | std::ios::in);
        }

        if (!in.is_open()) {
            std::cout << "Error: Invalid file path!\n";
            return;
        }

        in.seekg(0, std::ios::end);
        std::streampos size = in.tellg();
        in.seekg(0, std::ios::beg);


        openedFile = true;
        openedFilePath = filePath;
        setFileName();

        while (in.tellg() != size && !in.eof()) {
            Authomat a;
            a.read(in);
            ALists::automatons.push_back(a);
        }

        std::cout << "Successfully opened " << fileName << "!\n";
        in.close();
    }
    else std::cerr << "There is already an opened file! You can close the file with 'close'\n";
}

void Commands::close() {
    if (Commands::openedFile) {
        openedFile = false;
        ALists::automatons.clear();
        std::cout << "Successfully closed " << fileName << "!\n";
    }
    else std::cerr << "There is not opened file! You can open file with 'open <file path>'\n";
}

void Commands::saveas(std::string filePath) {
    if (openedFile) {
        std::ofstream out(filePath, std::ios::binary | std::ios::out);

        if (!out.is_open()) {
            std::cerr << "Error: Invalid file path!\n";
            return;
        }


        openedFilePath = filePath;
        setFileName();

        for (Authomat s : ALists::automatons) {
            s.write(out);
        }

        std::cout << "Successfully saved " << fileName << "!\n";

        out.close();
    }
    else std::cerr << "There is not opened file! You can open file with 'open <file path>'\n";
}

void Commands::save() {
    if (openedFile) saveas(openedFilePath);
    else std::cerr << "There is not opened file! You can open file with 'open <file path>'\n";
}

void Commands::help() {
    std::cout << "Available commands:\n"
        << "help - shows all available commands\n"
        << "open <file path> - opens <file path>\n"
        << "exit - exits the program\n"
        << "\nThe following commands work only when a file is opened:\n"
        << "close - closes the current opened file\n"
        << "saveas <file path> - saves the current opened file in <file path>\n"
        << "save - saves the current opened file\n"
        << "save <id> <filename> - saves automaton with <id> in <filename>\n"
        << "list - prints a list of all ID's\n"
        << "print <id> - prints all transitions of the given automaton\n"
        << "empty <id> - checks if an automaton's language is empty\n"
        << "deterministic <id> - checks if an automate is deterministic\n"
        << "recognize <id> <word> - checks if the given word can be recognized by the automaton\n"
        << "union <id1> <id2> - finds the union of 2 automatons\n"
        << "concat <id1> <id2> - finds the concatenation of 2 automatons\n"
        << "un <id> - finds the automaton's UN\n"
        << "reg <regex> - creates an automaton by regular expression\n"
        << "determine <id> - determines an automaton\n"
        << "finite <id> - checks if the automaton has finite language\n";
}

void Commands::exit() {
    std::cout << "Exiting the program...\n";
    std::exit(0);
}


void Commands::list() {
    if (openedFile) {
        std::cout << "IDs:\n";
        for (Authomat a : ALists::automatons) {
            std::cout << a.getID() << std::endl;
        }
    }
    else std::cerr << "There is not opened file! You can open file with 'open <file path>'\n";
}

void Commands::print(int id) {
    if (openedFile) {
        if (id > 0 && id <= ALists::automatons.size()) {
            std::cout << "Transitions:\n";
            for (Transition t : ALists::automatons[id - 1].getTransitions()) {
                std::cout << "< From: " << t.from << ", Letter: " << t.letter << ", To: " << t.to << " >\n";
            }
        }
        else std::cerr << "Invalid id!\n";
    }
    else std::cerr << "There is not opened file! You can open file with 'open <file path>'\n";
}

void Commands::save(int id, std::string path) {
    if (openedFile) {
        if (id >= 1 && id <= ALists::automatons.size()) {
            std::ofstream out(path, std::ios::binary | std::ios::out);

            if (!out.is_open()) {
                std::cerr << "Error: Invalid file path!\n";
                return;
            }

            ALists::automatons[id - 1].write(out);

            std::cout << "Successfully saved automaton " << id << " in file " << fileName << "!\n";

            out.close();
        }
        else std::cerr << "Invalid id!\n";
    }
    else std::cerr << "There is not opened file! You can open file with 'open <file path>'\n";
}

void Commands::empty(int id) {
    if (openedFile) {
        if (id > 0 && id <= ALists::automatons.size()) {
            bool emptyAlphabet = ALists::automatons[id - 1].getBeginningStates().size() == 1 && ALists::automatons[id - 1].getStates().size() == 1 && ALists::automatons[id - 1].getEndingStates().size() == 0;
            std::cout << (emptyAlphabet ? "Empty!" : "Not empty!") << std::endl;
        }
        else std::cerr << "Invalid id!\n";
    }
    else std::cerr << "There is not opened file! You can open file with 'open <file path>'\n";
}

void Commands::deterministic(int id) {
    if (openedFile) {
        if (id >= 1 && id <= ALists::automatons.size()) {
            bool hasEpsilonTransitions = false, hasMultipleTransitionsOneLetter = false;

            for (Transition t : ALists::automatons[id - 1].getTransitions()) {
                if (t.letter == 238) hasEpsilonTransitions = true;
            }

            for (char state : ALists::automatons[id - 1].getStates()) {
                std::vector<std::pair<char, int>> transitionsCount;
                for (Transition t : ALists::automatons[id - 1].getTransitions()) {
                    if (t.from == state) {
                        int letterIndex = -1;
                        for (int i = 0; i < transitionsCount.size(); i++) {
                            if (t.letter == transitionsCount[i].first) letterIndex = i;
                        }
                        if (letterIndex > -1) transitionsCount[letterIndex].second++;
                        else transitionsCount.push_back(std::make_pair(t.letter, 1));
                    }
                }

                for (std::pair<char, int> p : transitionsCount) {
                    if (p.second > 1) hasMultipleTransitionsOneLetter = true;
                }
            }

            bool deterministic = ALists::automatons[id - 1].getBeginningStates().size() == 1 && !hasEpsilonTransitions && !hasMultipleTransitionsOneLetter;
            std::cout << "The automaton is " << (deterministic ? "deterministic" : "not deterministic") << std::endl;
        }
        else std::cerr << "Invalid id!\n";
    }
    else std::cerr << "There is not opened file! You can open file with 'open <file path>'\n";
}

void Commands::recognize(int id, std::string word) {
    if (openedFile) {
        if (id >= 1 && id <= ALists::automatons.size()) std::cout << word << (Operations::automatonWordRecognition(ALists::automatons[id - 1], word) ? " was recognized" : " wasn't recognized") << std::endl;
        else std::cerr << "Invalid id!\n";
    }
    else std::cerr << "There is not opened file! You can open file with 'open <file path>'\n";
}

void Commands::_union(int id1, int id2) {
    if (openedFile) {
        if ((id1 >= 1 && id1 <= ALists::automatons.size()) && (id2 >= 1 && id2 <= ALists::automatons.size())) {
            ALists::automatons.push_back(Operations::automatonUnion(ALists::automatons[id1 - 1], ALists::automatons[id2 - 1]));
            std::cout << "New automaton's id: " << ALists::automatons.back().getID() << std::endl;
        }
        else std::cerr << "Invalid id!\n";
    }
    else std::cerr << "There is not opened file! You can open file with 'open <file path>'\n";
}

void Commands::concat(int id1, int id2) {
    if (openedFile) {
        if ((id1 >= 1 && id1 <= ALists::automatons.size()) && (id2 >= 1 && id2 <= ALists::automatons.size())) {
            ALists::automatons.push_back(Operations::automatonConcat(ALists::automatons[id1 - 1], ALists::automatons[id2 - 1]));
            std::cout << "New automaton's id: " << ALists::automatons.back().getID() << std::endl;
        }
        else std::cerr << "Invalid id!\n";
    }
    else std::cerr << "There is not opened file! You can open file with 'open <file path>'\n";
}

void Commands::un(int id) {
    if (openedFile) {
        if (id >= 1 && id <= ALists::automatons.size()) {
            ALists::automatons.push_back(Operations::automatonUN(ALists::automatons[id - 1]));
            std::cout << "New automaton's id: " << ALists::automatons.back().getID() << std::endl;
        }
        else std::cerr << "Invalid id!\n";
    }
    else std::cerr << "There is not opened file! You can open file with 'open <file path>'\n";
}

void Commands::reg(std::string regex) {
    if (openedFile) {
        if (RegexUtils::isValidRegex(regex)) {
            regex = RegexUtils::addPointsWhereAreMissing(regex);
            ALists::automatons.push_back(Operations::convertRegex(regex));
            ALists::automatons.back().setID(ALists::automatons.size());
            std::cout << "New automaton's id: " << ALists::automatons.back().getID() << std::endl;
        }
        else std::cerr << "Invalid regular expression!\n";
    }
    else std::cerr << "There is not opened file! You can open file with 'open <file path>'\n";
}

void Commands::determine(int id) {
    if (openedFile) {
        if (id >= 1 && id <= ALists::automatons.size()) {
            ALists::automatons[id - 1].determinite();
            std::cout << "The automaton was determinited successfully!\n";
        }
        else std::cerr << "Invalid id!\n";
    }
    else std::cerr << "There is not opened file! You can open file with 'open <file path>'\n";
}

void Commands::isFiniteLang(int id) {
    if (openedFile) {
        if (id >= 1 && id <= ALists::automatons.size()) {
            std::cout << "The automaton haregs " << (ALists::automatons[id - 1].isFiniteLang() ? "a finite language!\n" : "not a finite language!\n");
        }
        else std::cerr << "Invalid id!\n";
    }
    else std::cerr << "There is not opened file! You can open file with 'open <file path>'\n";
}

void Commands::run() {
    std::cout << "Welcome to KNA!\n";
    while (true) {
        std::string command;
        std::cout << "\n> ";
        getline(std::cin, command);
        command = StringHelper::clearAllConsecutiveSpacesQ(StringHelper::stripBegin(StringHelper::strip(command)));
        std::string* separatedCommand = StringHelper::splitQ(command);
        int commandArguments = StringHelper::countQ(command, ' ') + 1;

        if (StringHelper::toLowerCase(separatedCommand[0]) == "exit") {
            if (commandArguments > 1) std::cerr << "Too much arguments for this command!\n";
            else if (commandArguments < 1) std::cerr << "Too few arguments for this command!\n";
            else {
                delete[] separatedCommand;
                exit();
            }
        }
        else if (StringHelper::toLowerCase(separatedCommand[0]) == "open") {
            if (commandArguments > 2) std::cerr << "Too much arguments for this command!\n";
            else if (commandArguments < 2) std::cerr << "Too few arguments for this command!\n";
            else {
                separatedCommand[1] = StringHelper::strip(StringHelper::stripBegin(separatedCommand[1], '"'), '"');
                open(separatedCommand[1]);
            }
        }
        else if (StringHelper::toLowerCase(separatedCommand[0]) == "close") {
            if (commandArguments > 1) std::cerr << "Too much arguments for this command!\n";
            else if (commandArguments < 1) std::cerr << "Too few arguments for this command!\n";
            else close();
        }
        else if (StringHelper::toLowerCase(separatedCommand[0]) == "help") {
            if (commandArguments > 1) std::cerr << "Too much arguments for this command!\n";
            else if (commandArguments < 1) std::cerr << "Too few arguments for this command!\n";
            else help();
        }
        else if (StringHelper::toLowerCase(separatedCommand[0]) == "save") {
            if (commandArguments > 3) std::cerr << "Too much arguments for this command!\n";
            else if (commandArguments < 1 || commandArguments == 2) std::cerr << "Too few arguments for this command!\n";
            else {
                if (commandArguments == 1) save();
                else {
                    if (StringHelper::isNumber(separatedCommand[1])) save(std::atoi(separatedCommand[1].c_str()), StringHelper::strip(StringHelper::stripBegin(separatedCommand[2], '"'), '"'));
                    else std::cerr << "Invalid arguments!\n";
                }
            }
        }
        else if (StringHelper::toLowerCase(separatedCommand[0]) == "saveas") {
            if (commandArguments > 2) std::cerr << "Too much arguments for this command!\n";
            else if (commandArguments < 2) std::cerr << "Too few arguments for this command!\n";
            else {
                separatedCommand[1] = StringHelper::strip(StringHelper::stripBegin(separatedCommand[1], '"'), '"');
                saveas(separatedCommand[1]);
            }
        }
        else if (StringHelper::toLowerCase(separatedCommand[0]) == "list") {
            if (commandArguments > 1) std::cerr << "Too much arguments for this command!\n";
            else if (commandArguments < 1) std::cerr << "Too few arguments for this command!\n";
            else list();
        }
        else if (StringHelper::toLowerCase(separatedCommand[0]) == "print") {
            if (commandArguments > 2) std::cerr << "Too much arguments for this command!\n";
            else if (commandArguments < 2) std::cerr << "Too few arguments for this command!\n";
            else {
                if (StringHelper::isNumber(separatedCommand[1])) print(std::atoi(separatedCommand[1].c_str()));
                else std::cerr << "Invalid arguments!\n";
            }
        }
        else if (StringHelper::toLowerCase(separatedCommand[0]) == "empty") {
            if (commandArguments > 2) std::cerr << "Too much arguments for this command!\n";
            else if (commandArguments < 2) std::cerr << "Too few arguments for this command!\n";
            else {
                if (StringHelper::isNumber(separatedCommand[1])) empty(std::atoi(separatedCommand[1].c_str()));
                else std::cerr << "Invalid arguments!\n";
            }
        }
        else if (StringHelper::toLowerCase(separatedCommand[0]) == "deterministic") {
            if (commandArguments > 2) std::cerr << "Too much arguments for this command!\n";
            else if (commandArguments < 2) std::cerr << "Too few arguments for this command!\n";
            else {
                if (StringHelper::isNumber(separatedCommand[1])) deterministic(std::atoi(separatedCommand[1].c_str()));
                else std::cerr << "Invalid arguments!\n";
            }
        }
        else if (StringHelper::toLowerCase(separatedCommand[0]) == "recognize") {
            if (commandArguments > 3) std::cerr << "Too much arguments for this command!\n";
            else if (commandArguments < 3) std::cerr << "Too few arguments for this command!\n";
            else {
                if (StringHelper::isNumber(separatedCommand[1])) recognize(std::atoi(separatedCommand[1].c_str()), separatedCommand[2]);
                else std::cerr << "Invalid arguments!\n";
            }
        }
        else if (StringHelper::toLowerCase(separatedCommand[0]) == "union") {
            if (commandArguments > 3) std::cerr << "Too much arguments for this command!\n";
            else if (commandArguments < 3) std::cerr << "Too few arguments for this command!\n";
            else {
                if (StringHelper::isNumber(separatedCommand[1]) && StringHelper::isNumber(separatedCommand[2])) _union(std::atoi(separatedCommand[1].c_str()), std::atoi(separatedCommand[2].c_str()));
                else std::cerr << "Invalid arguments!\n";
            }
        }
        else if (StringHelper::toLowerCase(separatedCommand[0]) == "concat") {
            if (commandArguments > 3) std::cerr << "Too much arguments for this command!\n";
            else if (commandArguments < 3) std::cerr << "Too few arguments for this command!\n";
            else {
                if (StringHelper::isNumber(separatedCommand[1]) && StringHelper::isNumber(separatedCommand[2])) concat(std::atoi(separatedCommand[1].c_str()), std::atoi(separatedCommand[2].c_str()));
                else std::cerr << "Invalid arguments!\n";
            }
        }
        else if (StringHelper::toLowerCase(separatedCommand[0]) == "un") {
            if (commandArguments > 2) std::cerr << "Too much arguments for this command!\n";
            else if (commandArguments < 2) std::cerr << "Too few arguments for this command!\n";
            else {
                if (StringHelper::isNumber(separatedCommand[1])) un(std::atoi(separatedCommand[1].c_str()));
                else std::cerr << "Invalid arguments!\n";
            }
        }
        else if (StringHelper::toLowerCase(separatedCommand[0]) == "reg") {
            if (commandArguments > 2) std::cerr << "Too much arguments for this command!\n";
            else if (commandArguments < 2) std::cerr << "Too few arguments for this command!\n";
            else reg(separatedCommand[1]);
        }
        else if (StringHelper::toLowerCase(separatedCommand[0]) == "determine") {
            if (commandArguments > 2) std::cerr << "Too much arguments for this command!\n";
            else if (commandArguments < 2) std::cerr << "Too few arguments for this command!\n";
            else {
                if (StringHelper::isNumber(separatedCommand[1])) determine(std::atoi(separatedCommand[1].c_str()));
                else std::cerr << "Invalid arguments!\n";
            }
        }
        else if (StringHelper::toLowerCase(separatedCommand[0]) == "finite") {
            if (commandArguments > 2) std::cerr << "Too much arguments for this command!\n";
            else if (commandArguments < 2) std::cerr << "Too few arguments for this command!\n";
            else {
                if (StringHelper::isNumber(separatedCommand[1])) isFiniteLang(std::atoi(separatedCommand[1].c_str()));
                else std::cerr << "Invalid arguments!\n";
            }
        }
        else if (!command.empty()) std::cerr << "Invalid command! Please type 'help' to see all available commands!\n";

        delete[] separatedCommand;
    }
}
=======
>>>>>>> 8983b3930fb6ca799b6d3e0427ff30f459408f58
