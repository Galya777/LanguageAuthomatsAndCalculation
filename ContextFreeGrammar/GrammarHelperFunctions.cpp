//
// Created by Aleksandar on 20/05/2019.
//

#include "GrammarHelperFunctions.h"

bool isVariable(char k)
{
    return (k>='A'&&k<='Z');
}
bool checkIfNew(char c,const vector<char> &v)
{
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==c)return false;
    }
    return true;
}
char getFreeVar(int used[])
{
    for(char i='A';i<='Z';i++)
    {
        if(used[i]==0)return i;
    }
    return 0;
}
void generateAllRulesAfterEpsilon(int x, char newRuleName,string expr, string newExpr, bool hasEpsilon[], vector<Rule> &newRules)
{
    if(x==expr.size())
    {
        if(newExpr.size()>0&&newExpr.size()<expr.size())
        {
            newRules.push_back(Rule(0,newRuleName,newExpr));
        }
        return;
    }
    if(hasEpsilon[expr[x]])
    {
        generateAllRulesAfterEpsilon(x+1,newRuleName,expr,newExpr,hasEpsilon,newRules);

    }generateAllRulesAfterEpsilon(x+1,newRuleName,expr,newExpr+expr[x],hasEpsilon,newRules);
}
bool hasSingleVar(vector<Rule> rules)
{
    string expr;
    for(int i=0;i<rules.size();i++)
    {
        expr=rules[i].getExpr();
        if(expr.size()==1&&isVariable(expr[0]))return true;
    }
    return false;
}
bool cmpChom(Rule a,Rule b)
{
    if(a.getExpr()==b.getExpr())
    {
        return a.getRuleName()<b.getRuleName();
    }
    else
    {
        return a.getExpr()<b.getExpr();
    }

}
bool cmp(Rule a, Rule b)
{
    return a.getRuleID()<b.getRuleID();
}