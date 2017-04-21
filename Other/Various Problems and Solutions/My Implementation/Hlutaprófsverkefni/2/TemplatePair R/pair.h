#ifndef PAIR_H
#define PAIR_H

#include <ostream>

using namespace std;

template <class T1, class T2>
class Pair
{
    public:
        Pair(T1 one, T2 two) : first(one), second(two) {}
        virtual ~Pair() {}

        friend ostream& operator <<(ostream& out, const Pair& p) {
            out << "{" << p.first << ", " << p.second << "}" << endl;
            return out;
        }

    protected:

    private:
        T1 first;
        T2 second;
};

#endif // PAIR_H
