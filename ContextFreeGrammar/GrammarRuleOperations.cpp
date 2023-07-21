//
// Created by Aleksandar on 20/05/2019.
//
#include "Grammar.h"
#include "GrammarHelperFunctions.h"

void Grammar::addRule(Rule newRule)
{
    int varCnt=rules.size();

    char ruleName = newRule.getRuleName();
    string ruleExpr = newRule.getExpr();

    if(checkIfNew(ruleName,Vars))
    {
        Vars.push_back(ruleName);
    }
    for(int i=0;i<ruleExpr.size();i++)
    {
        if(isVariable(ruleExpr[i]))
        {
            if(checkIfNew(ruleExpr[i],Vars))
            {
                Vars.push_back(ruleExpr[i]);
            }
        }
        else if(ruleExpr[i]!='*')
        {
            if(checkIfNew(ruleExpr[i],Terms))
            {
                Terms.push_back(ruleExpr[i]);
            }
        }
    }


    for(int i=0;i<varCnt;i++)
    {
        if(rules[i].first==ruleName)
        {
            ruleCnt++;
            newRule.setRuleID(ruleCnt);
            rules[i].second.push_back(newRule);
            return;
        }
    }

    ruleCnt++;
    if(ruleCnt==1)startVar=ruleName;
    newRule.setRuleID(ruleCnt);
    pair<char,vector<Rule>> temp;
    temp.first=ruleName;
    temp.second.push_back(newRule);
    rules.push_back(temp);
}

void Grammar::removeRule(int n)
{
    for(int i=0;i<rules.size();i++)
    {
        for(int j=0;j<rules[i].second.size();j++)
        {
            if(rules[i].second[j].getRuleID()==n)
            {
                rules[i].second.erase(rules[i].second.begin()+j);
                if(rules[i].second.size()==0)rules.erase(rules.begin()+i);
                return;
            }
        }
    }
}
