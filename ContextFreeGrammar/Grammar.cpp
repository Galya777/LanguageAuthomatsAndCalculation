#include "Grammar.h"
#include "GrammarHelperFunctions.h"

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int Grammar::cnt = 0;
Grammar::Grammar()
{
    cnt++;
    id=cnt;
    ruleCnt=0;
    ogID=id;
    startVar='.';
}
int Grammar::getID()
{
    return id;
}
void Grammar::getNewID()
{
    cnt++;
    id=cnt;
    ogID=id;
}

void Grammar::cpy(const Grammar& other)
{
    startVar=other.startVar;
    rules=other.rules;
    Vars=other.Vars;
    Terms=other.Terms;
    if(other.ogID==0)
    {
        cnt++;
        id=cnt;
    }
    else
    {
        id=other.id;
        ogID=other.ogID;
    }
    ruleCnt=other.ruleCnt;
}
Grammar::Grammar(const Grammar& other)
{
    cpy(other);
}
Grammar& Grammar::operator=(const Grammar& other)
{
    if(this!=&other)
    {
        cpy(other);
    }
    return *this;
}
void Grammar::resetRuleCnt()
{
    ruleCnt=0;
}
void Grammar::setStartVar(char startVar)
{
    this->startVar=startVar;
}
char Grammar::getStartVar() const
{
    return startVar;
}

void Grammar::iter()
{
    //vector<pair<char,vector<Rule>>> newRules;
    //newRules=rules;

    bool flag;
    char freeVar='.';
    for(char i='A';i<='Z';i++)
    {
        flag=false;
        for(int j=0;j<Vars.size();j++)
        {
            if(Vars[j]==i)
            {
                flag=true;
            }
        }
        if(!flag)
        {
            freeVar=i;
            break;
        }
    }
    string expr;
    expr+=startVar;
    expr+=freeVar;
    addRule(Rule(0,freeVar,"*"));
    addRule(Rule(0,freeVar,expr));
    startVar=freeVar;
}


bool Grammar::checkChomsky()
{
    string expr;
    for(int i=0;i<rules.size();i++)
    {
        for(int j=0;j<rules[i].second.size();j++)
        {
            expr=rules[i].second[j].getExpr();
            if(expr.size()>2)return false;
            else if(expr.size()==1 && ( isVariable(expr[0]) || expr[0]=='*' ) ) return false;
            else if(expr.size()==2 && ( !isVariable(expr[0]) || !isVariable(expr[1]) ))return false;
        }
    }
    return true;
}

