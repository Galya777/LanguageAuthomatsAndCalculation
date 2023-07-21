//
// Created by Aleksandar on 20/05/2019.
//
#include <cstring>
#include "Grammar.h"
#include "GrammarHelperFunctions.h"

pair<pair<Grammar,char>,char> Grammar::combineRules(const Grammar& other)
{
    Grammar tempGrammar;
    int used[256];
    Rule newRule;
    memset(used,0,sizeof(used));
    string curExpr;
    char curRuleName;
    for(int i=0;i<rules.size();i++)
    {
        used[rules[i].first] = -1;
        for (int j = 0; j < rules[i].second.size(); j++)
        {
            curExpr = rules[i].second[j].getExpr();
            for (int k = 0; k < curExpr.size(); k++)
            {
                used[curExpr[k]] = -1;
            }
            tempGrammar.addRule(rules[i].second[j]);
        }
    }
    for(int i=0;i<other.rules.size();i++)
    {
        for (int j = 0; j < other.rules[i].second.size(); j++)
        {
            if(used[other.rules[i].first]==0)used[other.rules[i].first]=-2;
            curExpr = other.rules[i].second[j].getExpr();
            for (int k = 0; k < curExpr.size(); k++)
            {
                if(used[curExpr[k]]==0)used[curExpr[k]]=-2;
            }
        }
    }

    for(int i=0;i<other.rules.size();i++)
    {
        for(int j=0;j<other.rules[i].second.size();j++)
        {
            curExpr = other.rules[i].second[j].getExpr();
            for (int k = 0; k < curExpr.size(); k++)
            {
                if(used[curExpr[k]]>0)
                {

                    curExpr[k]=used[curExpr[k]];
                }

                else if(used[curExpr[k]]==-1)
                {
                    if(isVariable(curExpr[k]))
                    {
                        for(char t='A';t<='Z';t++)
                        {
                            if(used[t]==0)
                            {
                                used[t]=-1;
                                used[curExpr[k]]=t;
                                curExpr[k]=t;
                                break;
                            }
                        }
                    }
                    else
                    {
                        for(char t='a';t<='z';t++)
                        {
                            if(used[t]==0)
                            {
                                used[t]=-1;
                                used[curExpr[k]]=t;
                                curExpr[k]=t;
                                break;
                            }
                        }
                    }
                }
            }
            curRuleName=other.rules[i].first;
            if(used[other.rules[i].first]>0)
            {
                curRuleName=used[other.rules[i].first];
            }
            else if(used[other.rules[i].first]==-1)
            {
                for(char t='A';t<='Z';t++)
                {
                    if(used[t]==0)
                    {
                        used[t]=-1;
                        used[other.rules[i].first]=t;
                        curRuleName=t;
                        break;
                    }
                }
            }
            newRule.setRuleExpr(curExpr);

            newRule.setRuleName(curRuleName);
            tempGrammar.addRule(newRule);
        }
    }

    char otherStartVar;
    if(used[other.getStartVar()]>0)otherStartVar=used[other.getStartVar()];
    else otherStartVar=other.getStartVar();

    char freeVar;
    for(int i='A';i<='Z';i++)
    {
        if(used[i]==0)
        {
            freeVar=i;
            break;
        }
    }

    return make_pair(make_pair(tempGrammar,otherStartVar),freeVar);
}
