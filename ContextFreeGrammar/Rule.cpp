#include "Rule.h"

#include<string>
using namespace std;

Rule::Rule()
{
    name='.';
    id=0;
    expr="";
}
Rule::Rule(int id, char name, string expr)
{
    this->name=name;
    this->id=id;
    this->expr=expr;
}
Rule::Rule(int id, char name, char expr)
{
    this->name=name;
    this->id=id;
    this->expr=expr;
}
void Rule::cpy(const Rule& other)
{
    name=other.name;
    id=other.id;
    expr=other.expr;
}
Rule::Rule(const Rule& other)
{
    cpy(other);
}
Rule& Rule::operator=(const Rule& other)
{
    if(this!=&other)
    {
        cpy(other);
    }
    return *this;
}

char Rule::getRuleName()
{
    return name;
}
int Rule::getRuleID()
{
    return id;
}
string Rule::getExpr() const {
    return expr;
}
void Rule::setRuleID(int id)
{
    this->id=id;
}
void Rule::setRuleExpr(string expr)
{
    this->expr=expr;
}
void Rule::setRuleName(char name)
{
    this->name=name;
}