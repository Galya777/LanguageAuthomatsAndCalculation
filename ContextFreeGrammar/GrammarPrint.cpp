//
// Created by Aleksandar on 20/05/2019.
//

#include "Grammar.h"
#include "GrammarHelperFunctions.h"
#include <algorithm>
#include <iostream>

vector<Rule> Grammar::getSortedRulesByID()
{
    vector<Rule>temp;
    int varNum=rules.size();
    int varSz;
    for(int i=0;i<varNum;i++)
    {
        varSz=rules[i].second.size();
        for(int j=0;j<varSz;j++)
        {
            temp.push_back(rules[i].second[j]);
        }
    }
    sort(temp.begin(),temp.end(),cmp);
    return temp;
}
void Grammar::prenumGrammar()
{
    vector<Rule>temp=getSortedRulesByID();
    int sz=temp.size();
    rules.clear();
    char realStartVar=startVar;
    resetRuleCnt();
    for(int i=0;i<sz;i++)
    {
        addRule(temp[i]);
    }
    startVar=realStartVar;
}
void Grammar::printGrammar(ostream& os)
{
    prenumGrammar();
    os<<"Variables:";
    for(int i=0;i<Vars.size();i++)
    {
        os<<" "<<Vars[i];
    }os<<endl;
    os<<"Terminals:";
    for(int i=0;i<Terms.size();i++)
    {
        os<<" "<<Terms[i];
    }os<<endl;
    os<<"Start: "<<startVar<<endl;
    os<<"Rules:\n";
    for(int i=0;i<rules.size();i++)
    {
        for(int j=0;j<rules[i].second.size();j++)
        {
            os<<rules[i].second[j].getRuleID()<<" "<<rules[i].first<<" "<<rules[i].second[j].getExpr()<<endl;
        }
    }
}
