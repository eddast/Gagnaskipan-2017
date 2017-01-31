#ifndef PAIR_H
#define PAIR_H

template <class P1, class P2>
class Pair
{
    public:
        Pair() {};
        virtual ~Pair() {};

        P1 v1;
        P2 v2;

        friend ostream& operator <<(ostream& out, const Pair& p)
        {
            out << "Pair's V1: " << p.v1 << endl;
            out << "Pair's V2: " << p.v2 << endl;

            return out;
        }

    protected:

    private:
};

#endif // PAIR_H
