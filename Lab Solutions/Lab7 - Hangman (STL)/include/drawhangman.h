#ifndef DRAWHANGMAN_H
#define DRAWHANGMAN_H


class DrawHangman
{
    public:
        DrawHangman(){}
        virtual ~DrawHangman(){}
        void draw(int lives);
    private:
        void drawlost();
        void drawone();
        void drawtwo();
        void drawthree();
        void drawfour();
        void drawfive();
        void drawmore();
};

#endif // DRAWHANGMAN_H
