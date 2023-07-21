//
// Created by Aleksandar on 20/05/2019.
//

#include "Grammar.h"
#include "GrammarHelperFunctions.h"
#include <algorithm>
#include <iostream>
#include <cstring>

Grammar Grammar::chomsky()
{
    Grammar newChomskyGrammar;
    Rule rule;
    Rule newRule;
    string expr;
    string newExpr;
    char var;
    int used[256];
    memset(used,0,sizeof(used));
    for(int i=0;i<rules.size();i++)
    {
        for(int j=0;j<rules[i].second.size();j++)
        {
            rule=rules[i].second[j];
            expr=rule.getExpr();
            used[rules[i].first]=-1;
            for(int k=0;k<expr.size();k++)
            {
                used[expr[k]]=-1;
            }
        }
    }
    for(int i=0;i<rules.size();i++)
    {
        for(int j=0;j<rules[i].second.size();j++)
        {
            rule=rules[i].second[j];
            expr=rule.getExpr();
            if(expr.size()==1)
            {
                newChomskyGrammar.addRule(rule);
            }
            else
            {
                for(int k=0;k<expr.size();k++)
                {
                    if(!isVariable(expr[k]))
                    {
                        if(used[expr[k]]==-1)
                        {
                            var = getFreeVar(used);
                            used[expr[k]] = var;
                            used[var] = -1;
                            newChomskyGrammar.addRule(Rule(0,var,expr[k]));
                            expr[k] = var;

                        }
                        else
                        {
                            expr[k]=used[expr[k]];
                        }
                    }
                }
                var=rules[i].second[j].getRuleName();

                while(expr.size()>2)
                {
                    rule.setRuleName(var);

                    var=getFreeVar(used);

                    newExpr=expr[0];
                    newExpr+=var;

                    rule.setRuleExpr(newExpr);

                    newChomskyGrammar.addRule(rule);

                    used[var]=-1;
                    expr.erase(0,1);
                }
                rule.setRuleName(var);
                rule.setRuleExpr(expr);
                newChomskyGrammar.addRule(rule);
            }
        }
    }
    bool hasEpsilon[256],addEpsilonToStart=false;
    bool foundNewEpsilonRule=true,flag;
    memset(hasEpsilon,0,sizeof(hasEpsilon));

    for(int i=0;i<newChomskyGrammar.rules.size();i++)
    {
        for(int j=0;j<newChomskyGrammar.rules[i].second.size();j++)
        {
            rule=newChomskyGrammar.rules[i].second[j];
            if(rule.getExpr()=="*")
            {
                newChomskyGrammar.removeRule(rule.getRuleID());
                hasEpsilon[newChomskyGrammar.rules[i].first]=true;
                addEpsilonToStart=true;
            }
        }
    }
    while(foundNewEpsilonRule)
    {
        foundNewEpsilonRule=false;
        for (int i = 0; i < newChomskyGrammar.rules.size(); i++)
        {
            if(!hasEpsilon[newChomskyGrammar.rules[i].first])
            {
                for (int j = 0; j < newChomskyGrammar.rules[i].second.size(); j++)
                {
                    rule = newChomskyGrammar.rules[i].second[j];
                    expr = rule.getExpr();
                    flag = false;
                    for (int k = 0; k < expr.size(); k++)
                    {
                        if(!hasEpsilon[expr[k]])flag=true;
                    }
                    if(!flag)
                    {
                        hasEpsilon[newChomskyGrammar.rules[i].first]=true;
                        foundNewEpsilonRule=true;
                        break;
                    }
                }
            }
        }
    }
    vector<Rule> newRulesAfterEpsilon;
    for(int i=0;i<newChomskyGrammar.rules.size();i++)
    {
        for(int j=0;j<newChomskyGrammar.rules[i].second.size();j++)
        {
            generateAllRulesAfterEpsilon(0, newChomskyGrammar.rules[i].first, newChomskyGrammar.rules[i].second[j].getExpr(), "", hasEpsilon, newRulesAfterEpsilon);
        }
    }
    sort(newRulesAfterEpsilon.begin(),newRulesAfterEpsilon.end(),cmpChom);
    if(!newRulesAfterEpsilon.empty())
    {
        newChomskyGrammar.addRule(newRulesAfterEpsilon[0]);

        for (int i = 1; i < newRulesAfterEpsilon.size(); i++)
        {
            if (newRulesAfterEpsilon[i - 1].getExpr() != newRulesAfterEpsilon[i].getExpr()
                || newRulesAfterEpsilon[i].getRuleName() != newRulesAfterEpsilon[i-1].getRuleName())
            {
                newChomskyGrammar.addRule(newRulesAfterEpsilon[i]);
            }
        }
    }
    newChomskyGrammar.removeSingleRules();
    newChomskyGrammar.removeDupeRules();
    newChomskyGrammar.setStartVar(startVar);
    if(addEpsilonToStart)newChomskyGrammar.addRule(Rule(0,newChomskyGrammar.getStartVar(),"*"));

    return newChomskyGrammar;
}