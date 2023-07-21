cmake_minimum_required(VERSION 3.14)
project(CFG)

set(CMAKE_CXX_STANDARD 14)

add_executable(CFG main.cpp Grammar.cpp Grammar.h Rule.cpp Rule.h GrammarHelperFunctions.cpp GrammarHelperFunctions.h GrammarChomsky.cpp GrammarChomskyHelperFunctions.cpp GrammarPrint.cpp GrammarIsWordInLang.cpp GrammarCombineRules.cpp GrammarRuleOperations.cpp GrammarCheckEmpty.cpp CFG.cpp CFG.h)