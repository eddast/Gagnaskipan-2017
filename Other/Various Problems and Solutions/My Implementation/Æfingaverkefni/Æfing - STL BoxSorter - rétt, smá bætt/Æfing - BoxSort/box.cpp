#include "box.h"

using namespace std;

Box::Box(int i, int w, int d, int h)
{
    id = i;
    width = w;
    depth = d;
    height = h;

    // Added area variable for simplicity
    area = w*d;
}

ostream &operator <<(ostream &outs, const Box &box) {
    outs << "Box #" << box.id << ": (" << box.width << "," << box.depth << "," << box.height << ") - area: " << box.width * box.depth;
    return outs;
}

// Area determines which box is bigger than the other
// If areas are the equal, height determines which is bigger
// If heights are equal too, box with higher ID is considered "bigger"
bool operator <(const Box &box1, const Box &box2) {
    if(box1.area == box2.area)
    {
        if(box1.height == box2.height)
            return box1.id < box2.id;
        else
            return box1.height < box2.height;
    }
    else
    {
        return box1.area < box2.area;
    }
}
