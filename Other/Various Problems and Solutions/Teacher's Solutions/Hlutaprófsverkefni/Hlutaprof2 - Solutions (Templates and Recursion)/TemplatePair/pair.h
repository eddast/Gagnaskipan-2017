#ifndef PAIR_H
#define PAIR_H

#include <ostream>

using namespace std;

template <class T1, class T2>
class Pair
{
    public:
        Pair() {}
        Pair(T1 v1, T2 v2) {this->v1 = v1; this->v2 = v2;}
        virtual ~Pair() {}

        friend ostream& operator <<(ostream& out, const Pair& p) {

            out << "{" << p.v1 << ", " << p.v2 << "}";

            return out;
        }

    protected:

    private:
        T1 v1;
        T2 v2;
};

#endif // PAIR_H
