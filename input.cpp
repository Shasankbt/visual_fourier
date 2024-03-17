/*
    this opens a window to draw anything in a window
    outputs the dataPoints to the terminal directly -> tesing purpouses
    intended to be run in the shell script which directs to -> dataPoints.txt

    package used : Simplecpp
    window size used : 1920 * 1080
    output : coordinates seperated by ','

    **
        the code permits to draw only one stroke, the last and the first points are joined 
        try to draw everything in one go
    **
*/

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

double max(double a, double b){
    return (a > b ? a : b);
}

int main(){
    initCanvas("draw" , 1920, 1080);
    XEvent event;

    Point prev_point = Point(0,0);
    Point next_point = Point(0,0);
    Point start_point;
    Line path;

    while(true){
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

    // Filling out big bap between first & last point 
    if( max (abs(start_point.x - next_point.x) ,abs(start_point.y - next_point.y )) >= 50 ){
        int extra_points = max(abs(start_point.x - next_point.x) ,abs(start_point.y - next_point.y )) / 25;
        for(int i = 0; i<extra_points; i++){
            int a = (i * start_point.x + (extra_points - i) * next_point.x )/extra_points ;
            int b = (i * start_point.y + (extra_points - i) * next_point.y )/extra_points ;
            cout<<a<<','<<b<<endl;
        }
    }
    
    Text completeMsg(1000, 900,"the Data is taken , tap anywhere to close the window");
    
    getClick();
}

