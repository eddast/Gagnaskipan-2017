#ifndef BOX_H
#define BOX_H

#include <iostream>

using namespace std;

class Box
{
    public:
        Box(int i, int w, int d, int h);
        virtual ~Box(){}

        friend ostream &operator <<(ostream &outs, const Box &box);

        // Added operator for comparing boxes for size-ordering via set
        friend bool operator <(const Box &box1, const Box &box2);

    private:
        int id;
        int width;
        int depth;
        int height;

        // Added area variable for simplicity
        int area;
};

#endif // BOX_H
