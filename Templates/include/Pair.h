#ifndef PAIR_H
#define PAIR_H

template <class P>
class Pair
{
    public:
        Pair() {};
        virtual ~Pair() {};

        P v1;
        P v2;

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
