#include "Grammar.h"
#include "GrammarHelperFunctions.h"
#include <algorithm>
#include <iostream>
#include <cstring>


void Grammar::removeDupeRules()
{
    Rule rule;

    for(int i=0;i<rules.size();i++)
    {
        for(int j=0;j<rules[i].second.size();j++)
        {
            rule=rules[i].second[j];
            for(int k=j+1;k<rules[i].second.size();k++)
            {
                if(rule.getExpr()==rules[i].second[k].getExpr())
                {
                    removeRule(rules[i].second[k].getRuleID());
                }
            }
        }
    }
}



void Grammar::removeSingleRules()
{
    Rule rule,rule2;
    string expr;
    bool used[256];
    memset(used,0,sizeof(used));
    bool flag=true;
    while(flag)
    {
        flag=false;
        for(int i=0;i<rules.size();i++)
        {
            for(int j=0;j<rules[i].second.size();j++)
            {
                rule = rules[i].second[j];
                expr=rule.getExpr();
                if(expr.size()==1&&isVariable(expr[0]))
                {
                    for(int k=0;k<rules.size();k++)
                    {
                        if(k==i)continue;
                        if(rules[k].first==expr[0])
                        {
                            if(!hasSingleVar(rules[k].second))
                            {
                                used[k]=true;
                                flag=true;
                                removeRule(rules[i].second[j].getRuleID());
                                for(int t=0;t<rules[k].second.size();t++)
                                {
                                    rule2.setRuleName(rules[i].first);
                                    rule2.setRuleExpr(rules[k].second[t].getExpr());
                                    addRule(rule2);
                                }
                                j--;
                            }
                            break;
                        }
                    }
                }
            }
        }
    }
}