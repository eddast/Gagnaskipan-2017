#ifndef MATCH_H
#define MATCH_H
#include <iostream>

using namespace std;

class Match
{
    public:
        Match();
        Match(int id, string name, double hscore, double ascore);
        virtual ~Match();

        int mid;
        string mname;
        double mhscore;
        double mascore;

        friend ostream& operator <<(ostream& out, const Match& m1);

    private:
};

#endif // MATCH_H
