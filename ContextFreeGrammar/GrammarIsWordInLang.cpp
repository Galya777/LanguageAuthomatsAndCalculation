//
// Created by Aleksandar on 20/05/2019.
//
#include "Grammar.h"
#include "GrammarHelperFunctions.h"
#include <algorithm>
#include <iostream>

bool Grammar::isWordInLang(string word)
{
    int sz=word.size();
    vector<char> cyk[32][32];
    vector<char> used[32][32];
    Grammar chomskyGrammar=chomsky();
    Rule rule;
    string expr;
    for(int k=0;k<sz;k++)
    {
        for(int i=0;i<chomskyGrammar.rules.size();i++)
        {
            for(int j=0;j<chomskyGrammar.rules[i].second.size();j++)
            {
                rule=chomskyGrammar.rules[i].second[j];
                expr=rule.getExpr();
                if(expr.size()==1 && !isVariable(expr[0]))
                {
                    if(expr[0]==word[k])
                    {
                        cyk[1][k].push_back(chomskyGrammar.rules[i].first-'A');
                    }
                }
                else if(expr.size()==2)
                {
                    used[expr[0]-'A'][expr[1]-'A'].push_back(chomskyGrammar.rules[i].first-'A');
                }
            }
        }
    }

    bool flag;
    for(int i=2;i<=sz;i++)
    {
        for(int j=0;j<=sz-i;j++)
        {
            for(int k=1;k<i;k++)
            {
                for(int a=0;a<cyk[i-k][j].size();a++)
                {
                    for(int b=0;b<cyk[k][j+i-k].size();b++)
                    {
                        for(int c=0;c<used[cyk[i-k][j][a]][cyk[k][j+i-k][b]].size();c++)
                        {
                            flag=false;
                            for(int d=0;d<cyk[i][j].size();d++)
                            {
                                if(cyk[i][j][d]==used[cyk[i-k][j][a]][cyk[k][j+i-k][b]][c])flag=true;
                            }
                            if(!flag)
                            {
                                cyk[i][j].push_back(used[cyk[i-k][j][a]][cyk[k][j+i-k][b]][c]);
                            }
                        }
                    }
                }
            }
        }
    }
    /*  for(int k=1;k<=sz;k++) {
           for (int i = 0; i < sz - k + 1; i++) {
               for (int j = 0; j < cyk[k][i].size(); j++) {
                   cout << (char)(cyk[k][i][j] + 'A') << ", ";        /// PROOF THAT CYK WORKS
               }
               cout << " | ";
           }
           cout << endl;
   }*/
    for(int i=0;i<cyk[sz][0].size();i++)
    {
        if(cyk[sz][0][i]+'A'==startVar)return true;
    }
    return false;
}
