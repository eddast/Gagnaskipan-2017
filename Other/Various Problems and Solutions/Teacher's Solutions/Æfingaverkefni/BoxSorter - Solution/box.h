#ifndef BOX_H
#define BOX_H

#include <iostream>

using namespace std;

class Box
{
    public:
        Box(int i, int w, int d, int h);
        virtual ~Box();

        ///Bætti þessu við
        bool operator <(const Box &box) const;

        friend ostream &operator <<(ostream &outs, const Box &box);

    private:
        int id;
        int width;
        int depth;
        int height;
};

#endif // BOX_H
