#include<iostream>
#include<simplecpp>

struct Point{
    int x , y;
    Point(){}
    Point(int a, int b) : x(a), y(b){}

    Point & operator=(const Point & rhs){
        x = rhs.x;
        y = rhs.y;
        return *this;
    }
};

int main(){
    initCanvas("draw" , 1920, 1080);
    XEvent event;

    Point prev_point = Point(0,0);
    Point next_point = Point(0,0);
    Point start_point;
    Line path;

    while(true)
    {
        nextEvent(event);
        if(mouseButtonPressEvent(event)) { start_point.x = next_point.x = event.xbutton.x ; start_point.y = next_point.y = event.xbutton.y; }
        if(mouseDragEvent(event)){
            cout<<event.xmotion.x<<","<<event.xmotion.y<<endl; 
            prev_point = next_point;
            next_point.x = event.xmotion.x; next_point.y = event.xmotion.y;
            path = Line(prev_point.x, prev_point.y, next_point.x, next_point.y);
            path.imprint();
        }
        if(mouseButtonReleaseEvent(event)) break;
    }
    path = Line(start_point.x, start_point.y, next_point.x, next_point.y);
    path.imprint();
    
    getClick();
}

