//
// Created by Aleksandar on 03/06/2019.
//

#include "CFG.h"
#include<iostream>
#include<algorithm>
#include<fstream>
#include<string>

using namespace std;


int CFG::findIdPlace(int id)
{
    for(int i=0;i<grammars.size();i++)
    {
        if(grammars[i].getID()==id)return i;
    }
}
void CFG::Concat(const int id1,const int id2)
{
    //cout<<"\nConcat\n";
    pair<pair<Grammar,char>,char> q=grammars[id1].combineRules(grammars[id2]);

    char c=q.first.second;
    string newStartExpr="";
    newStartExpr+=c;
    newStartExpr+=q.first.first.getStartVar();
    Rule newStartRule(0,q.second,newStartExpr);
    q.first.first.addRule(newStartRule);
    q.first.first.setStartVar(q.second);
    grammars.push_back(q.first.first);
    cout<<"Successfully concatenated\n";
}
void CFG::Union(const int id1,const int id2)
{
    //cout<<"\nUnion\n";
    pair<pair<Grammar,char>,char> q=grammars[id1].combineRules(grammars[id2]);

    char c=q.first.second;
    string newStartExpr="";

    newStartExpr=c;

    Rule newStartRule(0,q.second,newStartExpr);
    q.first.first.addRule(newStartRule);



    newStartExpr=q.first.first.getStartVar();

    newStartRule.setRuleExpr(newStartExpr);
    q.first.first.addRule(newStartRule);




    q.first.first.setStartVar(q.second);

    grammars.push_back(q.first.first);

    cout<<"Successful union\n";
}

void CFG::Iter(const int id)
{
    //cout<<1<<endl;
    Grammar temp;
    temp=grammars[id];
    temp.iter();
    temp.getNewID();
    grammars.push_back(temp);
    cout<<"Successful iteration\n";
}
bool CFG::Chomsky(const int id)
{
    return grammars[id].checkChomsky();
}
void CFG::Chomskify(const int id)
{
   // cout<<"\nChomskyfy\n";
    Grammar q=grammars[id].chomsky();
    grammars.push_back(q);
    cout<<"Successfully Chomskified\n";
}
void CFG::List()
{
    if(grammars.empty())
    {
        cout<<"No grammars in list\n";
        return;
    }
    cout<<"\nList: ";
    vector<int> grammarIds;
    for(int i=0;i<grammars.size();i++)
    {
        grammarIds.push_back(grammars[i].getID());
    }

    sort(grammarIds.begin(),grammarIds.end());
    cout<<grammarIds[0];
    for(int i=1;i<grammarIds.size();i++)
    {
        if(grammarIds[i]!=grammarIds[i-1])
        {
            cout<<" "<<grammarIds[i];
        }
    }
    cout<<endl;
}
void CFG::Print(const int id)
{
    grammars[id].printGrammar(cout);
}
void CFG::Empty(int id)
{
    if(grammars[id].checkEmpty())cout<<"Grammar is empty\n";
    else cout<<"Grammar is not empty\n";
}
void CFG::CYK(int id, string word)
{
    //cout<<"\nCYK\n";
    if(grammars[id].isWordInLang(word))cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
void CFG::AddRule(const int id,const Rule rule)
{
    grammars[id].addRule(rule);
    cout<<"Successfully added rule\n";
}
void CFG::RemoveRule(const int id, const int n)
{
    grammars[id].removeRule(n);
    cout<<"Successfully removed rule\n";
}
void CFG::Open(const string file)
{
    ifstream fin(file);
    if (fin.fail())
    {
        cout<<"File does not exist\n";
        return ;
    }
    cout<<"Successfully opened file\n";
    Grammar newGrammar;
    char name;
    int temp;
    string expr;
    getline(fin,expr);
    getline(fin,expr);
    getline(fin,expr);
    char startVar=expr[expr.size()-1];
    getline(fin,expr);

    while(fin>>temp)
    {
        fin>>name;
        fin>>expr;
        newGrammar.addRule(Rule(0,name,expr));
    }
    newGrammar.setStartVar(startVar);
    grammars.push_back(newGrammar);
    fin.close();
}
void CFG::Save(const int id, const string file)
{
    ofstream fout(file);

    grammars[id].printGrammar(fout);
    cout<<"Successfully saved file\n";
    fout.close();
}