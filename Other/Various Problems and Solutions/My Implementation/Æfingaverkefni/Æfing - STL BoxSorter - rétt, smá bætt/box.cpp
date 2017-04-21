#include "box.h"

using namespace std;

Box::Box(int i, int w, int d, int h)
{
    id = i;
    width = w;
    depth = d;
    height = h;
}

Box::~Box()
{
    //dtor
}

ostream &operator <<(ostream &outs, const Box &box) {
    outs << "Box #" << box.id << ": (" << box.width << "," << box.depth << "," << box.height << ") - area: " << box.width * box.depth;
    return outs;
}
