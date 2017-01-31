#include "Match.h"

Match::Match()
{
    //ctor
}

Match::Match(int id, string name, double hscore, double ascore)
{
    mid = id;
    mname = name;
    mhscore = hscore;
    mascore = ascore;
}

Match::~Match()
{
    //dtor
}

ostream& operator <<(ostream& out, const Match& m1)
{
        cout << "["
         << "ID: " << m1.mid
         << ", Match: " << m1.mname
         << ", Home Score: " << m1.mhscore
         << ", Away Score: " << m1.mascore
         << "]" << endl;

         return out;
}
