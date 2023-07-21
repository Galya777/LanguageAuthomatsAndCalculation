//
// Created by Aleksandar on 20/05/2019.
//
#include <cstring>
#include "Grammar.h"
#include "GrammarHelperFunctions.h"

bool Grammar::checkEmpty()
{
    Rule rule;
    string expr;
    bool leadsToTerminal[256];
    bool foundNewTerminalRule=true,flag;
    memset(leadsToTerminal,0,sizeof(leadsToTerminal));

    for(int i=0;i<rules.size();i++)
    {
        for(int j=0;j<rules[i].second.size();j++)
        {
            rule=rules[i].second[j];
            expr=rule.getExpr();
            if(expr.size()==1 && !isVariable(expr[0]))
            {
                leadsToTerminal[rules[i].first]=true;
            }
        }
    }
    while(foundNewTerminalRule)
    {
        foundNewTerminalRule=false;
        for (int i = 0; i < rules.size(); i++)
        {
            if(!leadsToTerminal[rules[i].first])
            {
                for (int j = 0; j < rules[i].second.size(); j++)
                {
                    rule = rules[i].second[j];
                    expr = rule.getExpr();
                    flag = false;
                    for (int k = 0; k < expr.size(); k++)
                    {
                        if(!leadsToTerminal[expr[k]])flag=true;
                    }
                    if(!flag)
                    {
                        leadsToTerminal[rules[i].first]=true;
                        foundNewTerminalRule=true;
                        break;
                    }
                }
            }
        }
    }
    if(leadsToTerminal[startVar])return false;
    return true;
}

