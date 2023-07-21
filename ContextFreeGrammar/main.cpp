#include <iostream>
#include <string>
#include<fstream>
#include <algorithm>
#include "Grammar.h"
#include "CFG.h"
using namespace std;
int main()
{
    string command;
    string str;
    int id1,id2;
    char var;
    CFG allCFG; // Пази в паметта всички граматики
    while(cin>>command)
    {
        if(command=="Exit")
        {
            break;
        }
        else if(command=="Open")
        {
            cin>>str;
            allCFG.Open(str);
        }
        else if(command=="Save")
        {
            cin>>id1>>str;
            allCFG.Save(allCFG.findIdPlace(id1),str);
        }
        else if(command=="RemoveRule")
        {
            cin>>id1>>id2;
            allCFG.RemoveRule(allCFG.findIdPlace(id1),id2);
        }
        else if(command=="AddRule")
        {
            cin>>id1;
            cin>>var>>str;
            allCFG.AddRule(allCFG.findIdPlace(id1),Rule(0,var,str));
        }
        else if(command=="CYK")
        {
            cin>>id1>>str;
            allCFG.CYK(allCFG.findIdPlace(id1),str);
        }
        else if(command=="Empty")
        {
            cin>>id1;
            allCFG.Empty(allCFG.findIdPlace(id1));
        }
        else if(command=="Print")
        {
            cin>>id1;
            allCFG.Print(allCFG.findIdPlace(id1));
        }
        else if(command=="List")
        {
            allCFG.List();
        }
        else if(command=="Chomsky")
        {
            cin>>id1;
            if(allCFG.Chomsky(allCFG.findIdPlace(id1)))cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
        else if(command=="Chomskify")
        {
            cin>>id1;
            allCFG.Chomskify(allCFG.findIdPlace(id1));
        }
        else if(command=="Concat")
        {
            cin>>id1>>id2;
            allCFG.Concat(allCFG.findIdPlace(id1),allCFG.findIdPlace(id2));
        }
        else if(command=="Union")
        {
            cin>>id1>>id2;
            allCFG.Union(allCFG.findIdPlace(id1),allCFG.findIdPlace(id2));
        }
        else if(command=="Iter")
        {
            cin>>id1;
            //cout<<id1<<endl;
            allCFG.Iter(allCFG.findIdPlace(id1));
        }
        else
        {
            cout<<"Unknown command!\n";
        }
    }
    return 0;
}
/*vector<Grammar> Combine(const int id1,const int id2, vector<Grammar> grammars)
{
    cout<<"\nCombine\n";
    cout<<endl;
    pair<pair<Grammar,char>,char> q=grammars[id1].combineRules(grammars[id2]);
    grammars.push_back(q.first.first);
    return grammars;
}
void Concat(const int id1,const int id2, vector<Grammar> &grammars)
{
    cout<<"\nConcat\n";
    pair<pair<Grammar,char>,char> q=grammars[id1].combineRules(grammars[id2]);

    char c=q.first.second;
    string newStartExpr="";
    newStartExpr+=c;
    newStartExpr+=q.first.first.getStartVar();
    Rule newStartRule(0,q.second,newStartExpr);
    q.first.first.addRule(newStartRule);
    q.first.first.setStartVar(q.second);
    grammars.push_back(q.first.first);
}
void Union(const int id1,const int id2, vector<Grammar> &grammars)
{
    cout<<"\nUnion\n";
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
}

void Iter(const int id, vector<Grammar> &grammars)
{
    grammars[id].iter();
}
bool Chomsky(const int id,vector<Grammar> &grammars)
{
    return grammars[id].checkChomsky();
}
void Chomskify(const int id, vector<Grammar> &grammars)
{
    cout<<"\nChomskyfy\n";
    Grammar q=grammars[id].chomsky();
    grammars.push_back(q);
}
void List( vector<Grammar> &grammars)
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
void Empty(int id, vector<Grammar> &grammars)
{
    if(grammars[id].checkEmpty())cout<<"Grammar is empty\n";
    else cout<<"Grammar is not empty\n";
}
void CYK(int id, string word, vector<Grammar> &grammars)
{
    cout<<"\nCYK\n";
    if(grammars[id].isWordInLang(word))cout<<"Yes"<<endl;
    else cout<<"NO"<<endl;
}*/
/**
int main()
{
    Rule a(0,'S',"asd");
    Rule b(0,'S',"asaaABS");
    Rule c(0,'B',"a");
    Rule d(0,'S',"das");
    vector<Grammar> grammars;
    Grammar g,r,t,p;
    //cout<<g.getID()<<endl;
    g.addRule(a);
    g.addRule(b);
    g.addRule(c);
    g.addRule(d);
    // cout<<g.getID()<<endl;
    r.addRule(b);
    r.addRule(b);
   /// r.addRule(c);
    t.addRule(a);

    grammars.push_back(g);
    grammars.push_back(r);
    grammars.push_back(t);


    grammars=Combine(0,1,grammars);
    grammars[3].printGrammar(cout);
    grammars=Combine(0,3,grammars);
    grammars[4].printGrammar(cout);

cout<<"--------------"<<endl;
    vector<Grammar> asd;
    asd.push_back(r);
    asd.push_back(r);
    asd[0].printGrammar(cout);
    asd=Combine(0,1,asd);
    asd[2].printGrammar(cout);
    cout<<asd[2].getStartVar()<<endl;

    Concat(0,1,asd);

    asd[asd.size()-1].printGrammar(cout);
    cout<<"Start: "<<asd[asd.size()-1].getStartVar()<<endl;

    Iter(0,asd);

    asd[asd.size()-1].printGrammar(cout);
    cout<<"Start: "<<asd[asd.size()-1].getStartVar()<<endl;


            Union(0,1,asd);

    asd[asd.size()-1].printGrammar(cout);
    cout<<"Start: "<<asd[asd.size()-1].getStartVar()<<endl;

    asd[asd.size()-1].removeRule(3);
    cout<<"\nafter removal"<<endl;
    asd[asd.size()-1].printGrammar(cout);

    cout<<endl;
    cout<<endl;
    if(Chomsky(1,asd))cout<<"Yes\n";
    else cout<<"No\n";






    Rule aa(0,'S',"XaY");
    Rule ab(0,'S',"Z");
    Rule ac(0,'X',"*");
    Rule bb(0,'X',"b");
    Rule cc(0,'Y',"XZ");
    Rule dd(0,'Y',"XX");
    Rule ee(0,'Z',"b");

    Grammar o;
    o.addRule(aa);
    o.addRule(ab);
    o.addRule(ac);
    o.addRule(bb);
    o.addRule(cc);
    o.addRule(dd);
    o.addRule(ee);
    asd.push_back(o);

    if(Chomsky(asd.size()-1,asd))cout<<"Yes\n";
    else cout<<"No\n";
    asd[asd.size()-1].printGrammar(cout);

    Chomskify(asd.size()-1,asd);

    asd[asd.size()-1].printGrammar(cout);

    List(asd);
    Empty(asd.size()-1,asd);



   Rule sa(0,'S',"XB");      ///empty & CYK
    Rule sb(0,'X',"AB");
    Rule sc(0,'A',"B");
    Rule sd(0,'C',"B");
    Rule se(0,'B',"AXCb");
    Grammar oo;
    oo.addRule(sa);
    oo.addRule(sb);
    oo.addRule(sc);
    oo.addRule(sd);
    oo.addRule(se);
    asd.push_back(oo);
    Empty(asd.size()-1,asd);
    Chomskify(asd.size()-1,asd);
    Empty(asd.size()-1,asd);




    Rule ta(0,'S',"BC");
    Rule tb(0,'S',"AB");
    Rule tc(0,'A',"BA");
    Rule td(0,'A',"a");
    Rule te(0,'B',"CC");
    Rule tf(0,'B',"b");
    Rule tg(0,'C',"AB");
    Rule th(0,'C',"a");
    Grammar ooo;
    ooo.addRule(ta);
    ooo.addRule(tb);
    ooo.addRule(tc);
    ooo.addRule(td);
    ooo.addRule(te);
    ooo.addRule(tf);
    ooo.addRule(tg);
    ooo.addRule(th);
    asd.push_back(ooo);
    CYK(asd.size()-1,"baaba",asd);



    Rule pa(0,'S',"aSd");
    Rule pb(0,'S',"X");
    Rule pc(0,'X',"bbXc");
    Rule pd(0,'X',"*");
    Grammar oooo;
    oooo.addRule(pa);
    oooo.addRule(pb);
    oooo.addRule(pc);
    oooo.addRule(pd);
    asd.push_back(oooo);

    asd[asd.size()-1].printGrammar(cout);

    CYK(asd.size()-1,"abbcd",asd);

    Chomskify(asd.size()-1,asd);

    asd[asd.size()-1].printGrammar(cout);




    //Iter(asd.size()-1,asd);
   // asd[asd.size()-1].printGrammar(cout);
   // grammars[3].printGrammar(cout);





    Rule aaa(0,'S',"a");
    Rule aab(0,'S',"CA");
    Rule aac(0,'S',"CB");
    Rule aad(0,'B',"SA");
    Rule aae(0,'B',"CS");
    Rule aaf(0,'C',"a");
    Rule aag(0,'A',"b");
    Grammar ooooo;
    ooooo.addRule(aaa);
    ooooo.addRule(aab);
    ooooo.addRule(aac);
    ooooo.addRule(aad);
    ooooo.addRule(aae);
    ooooo.addRule(aaf);
    ooooo.addRule(aag);
    asd.push_back(ooooo);
    CYK(asd.size()-1,"aabba",asd);
    asd[asd.size()-1].printGrammar(cout);


    for(int i=0;i<grammars.size();i++)
    {
        string file="Grammar_";
        file+=char(i+'0');
        file+=".txt";
        ofstream fout(file);
        grammars[i].printGrammar(fout);
        fout.close();
    }
    for(int i=0;i<asd.size();i++)
    {
        string file="Grammar_";
        file+=char(i+'A');
        file+=".txt";
        ofstream fout(file);
        asd[i].printGrammar(fout);
        fout.close();
    }

    CFG test;
    test.Open("Grammar_I.txt");
    test.List();
    test.Print(0);
    test.Save(0,"test.txt");

    return 0;
}**/

