#include <simplecpp>
#include<iostream>
#include<ctime>
#include<cmath>

#define pi 2*acos(0.0)

struct Rotvec{
    double time_period;
    double rad;
    double phase;
    Rotvec * prevVecPtr;
    double centre[2];
    double x , y;

    Line radius;
    Circle path;

    double premultiplier;

    Rotvec(){}

    Rotvec(double tmprd ,double r, double p, Rotvec * prvc) : time_period(tmprd), rad(r), phase(p), prevVecPtr(prvc) {
        if(prvc != nullptr) {centre[0] = prevVecPtr->x ;centre[1] = prevVecPtr->y; }
        else {centre[0] = centre[1] = 0.0; }

        premultiplier = 2*M_PI*time_period;

        

        x = centre[0]+ rad*cos(p);
        y = centre[1] + rad*sin(p);

        //cout<<rad*cos(p)<<" "<<x<<endl;

        path = Circle(centre[0],centre[1],r);
        //cout<<"defined circle"<<endl;
        radius = Line(centre[0],centre[1], x, y);

        path.setFill(false);
        path.setColor(COLOR(160,160,160));
    }

    void animateTo(double current_time){
        if(prevVecPtr != nullptr) {centre[0] = prevVecPtr->x ;centre[1] = prevVecPtr->y; }

        //cout<<"here3"<<endl;
        x = centre[0] + rad*cos(premultiplier*current_time + phase);
        y =  centre[1] + rad*sin(premultiplier*current_time + phase);

        path = Circle(centre[0],centre[1],rad);
        radius = Line(centre[0],centre[1], x, y);    
    }
};

int main(){
    initCanvas("ejjj", 2000, 1700);
    int n = 49;
    // cout<<"enter n "<<endl;
    // cin>>n;

    Rotvec vec[2*n+1];

    {
        double r , p;
        cin>>r>>p;
        vec[0] = Rotvec(0 ,r, p , nullptr);
    }
    


    for(int i =1; i<n+1; i++){
        double r , p;
        cin>>r>>p;
        vec[2*i-1] = Rotvec(i ,r, p , &vec[2*i-2]);
        cin>>r>>p;
        vec[2*i] = Rotvec((-1)*i ,r, p , &vec[2*i-1]);
    }

    //Circle pointer = Circle(vec[2*n].x, vec[2*n].y,5);
    double draw[4] = {vec[2*n].x, vec[2*n].y,vec[2*n].x, vec[2*n].y,};
    //pointer.setFill(true);
    //pointer.setColor(COLOR("red"));
    cout<<"here1"<<endl;
    
    double curr_time = 0;
    clock_t start = clock();
    while(true){
        //double curr_time = 50000*(clock() - start)/CLOCKS_PER_SEC;
        curr_time += 0.005;
        for(int i =0; i<2*n+1; i++) vec[i].animateTo(curr_time);

        draw[0] = draw[2]; draw[1] = draw[3];
        draw[2] = vec[2*n].x ; draw[3] = vec[2*n].y;

        Line l(draw[0], draw[1], draw[2], draw[3]); l.imprint();

        //pointer.moveTo(vec[2*n].x, vec[2*n].y);

        //cout<<"here2"<<endl;

        //for(int i = 0; i<2*n+1 ;i++) cout<<vec[i].x<<" "; //<<vec[1].centre[0]<<","<<vec[1].centre[1]<<","<<vec[2].centre[0]<<","<<vec[2].centre[1]<<endl;
        //cout<<endl;
        //wait(0.02);
    }




    //vec.animate();
    getClick();
    
}