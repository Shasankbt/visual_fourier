#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;




struct Rotvec {
    double time_period;
    double rad;
    double phase;
    Rotvec *prevVecPtr;
    double centre[2];
    double x, y;

    Rotvec() {}

    Rotvec(double tmprd, double r, double p, Rotvec * prvc) : time_period(tmprd), rad(r), phase(p), prevVecPtr(prvc) {
        if (prvc != nullptr) {
            centre[0] = prevVecPtr->x;
            centre[1] = prevVecPtr->y;
        } else {
            centre[0] = centre[1] = 0.0;
        }
        x = centre[0]+ rad * cos(p);
        y = centre[1] + rad * sin(p);

        //cout<<x<<" "<<y<<",";
    }

    void animateTo(double current_time) {
        if (prevVecPtr != nullptr) {
            centre[0] = prevVecPtr->x;
            centre[1] = prevVecPtr->y;
        }

        x = centre[0] + rad * cos(2 * M_PI * time_period * current_time + phase);
        y = centre[1] + rad * sin(2 * M_PI * time_period * current_time + phase);
    }
};

vector<std::pair<float, float>> pathPoints;
vector<Rotvec> vec;
int n;

double curr_time = 0 ;

void display() {

    //pathPoints.clear();

    curr_time += 0.001  ;
    for(int i =1; i<2*n+1; i++) vec[i].animateTo(curr_time);

    glClear(GL_COLOR_BUFFER_BIT);

    
    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_LINES);
    for (int i = 1; i < 2*n+1; ++i) {
        glVertex2f(vec[i].centre[0], vec[i].centre[1]);
        glVertex2f(vec[i].x, vec[i].y);
    }
    glEnd();

    glLineWidth(2.0f);
    glColor3f(0.0f, 0.5f, 1.0f);
    glBegin(GL_LINE_STRIP);
    for (const auto& point : pathPoints) {
        glVertex2f(point.first, point.second);
    }
    glEnd();

    // for(int i=0; i<99; i++) cout<<"start:"<<vec[i].x<<" "<<vec[i].y<<",";
    // cout<<endl;
    // cout<<endl;

    //glFlush();
    glutSwapBuffers();
}

void timer(int value) {
    // Do something after 0.05 seconds
    pathPoints.push_back(std::make_pair(vec[2*n].x, vec[2*n].y));

    // Request redisplay to update the screen
    glutPostRedisplay();

    // Register the timer function to be called again after 0.05 seconds
    glutTimerFunc(50, timer, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("Forier Transformation");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1920, 1080, 0, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    cout<<"enter n ( c[-n],...,c[0],c[1],...,c[n]) :";
    cin>>n;

    {
        double r , p;
        std::cin>>r>>p;
        vec.push_back(Rotvec(0 ,r, p , nullptr));
    }

    for(int i = 1; i < n+1; i++){
        double r , p;
        std::cin>>r>>p;
        vec.push_back(Rotvec(i ,r, p , &vec[2*i-2]));
        std::cin>>r>>p;
        vec.push_back(Rotvec((-1)*i ,r, p , &vec[2*i-1]));
    }

    for(int i=0; i<99; i++) cout<<"start:"<<vec[i].x<<" "<<vec[i].y<<",";
    cout<<endl;

    glutDisplayFunc(display);
    glutTimerFunc(50, timer, 0);
    glutMainLoop();
    return 0;
}
