#include <bits/stdc++.h>
using namespace std;

struct vec3D{
    float x=0, y=0, z=0;
    vec3D(){}
    vec3D(float x, float y, float z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

struct quaternions{
    float a=0, b=0, c=0, d=0;
    quaternions(){}
    quaternions(float a, float b, float c, float d){
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
};

quaternions conjugate(quaternions q){
    quaternions q_;
    q_.a = q.a;
    q_.b = - q.b;
    q_.c = - q.c;
    q_.d = - q.d;
}

quaternions quartize(vec3D axis, float theta){
    quaternions q;
    q.a = cos(theta/2);
    
    q.b = sin(theta/2) * axis.x;
    q.c = sin(theta/2) * axis.y;
    q.d = sin(theta/2) * axis.z;
}

quaternions mul(quaternions x, quaternions y){
    quaternions ans(0,0,0,0);
    ans.a = x.a * y.a  -  x.b * y.b  -  x.c * y.c  -  x.d * y.d  ;
    ans.b = x.a * y.b  +  x.b * y.a  +  x.c * y.d  -  x.d * y.c  ;
    ans.c = x.a * y.c  +  x.c * y.a  +  x.d * y.b  -  x.b * y.d  ;
    ans.d = x.a * y.d  +  x.d * y.a  +  x.b * y.c  -  x.c * y.b  ;
    return ans;
}

quaternions rotate(vec3D pos, vec3D axis, float theta){
    
    //normalize axis
    float scl = sqrt(pow(axis.x,2) + pow(axis.y,2) + pow(axis.z,2));
    axis.x /= scl; axis.y /= scl; axis.z /= scl;
    
    quaternions q = quartize(axis, theta);
    quaternions q_ =conjugate(q) ;
    quaternions v = quartize(pos, 1.57); //default theta = 90

    quaternions rotated_v = mul(mul(q,v),q_) ;
    return rotated_v ;
}

void printvec3D(vec3D p){
    cout<<p.x<<","<<p.y<<","<<p.z<<endl;
}

void printQuar(quaternions q){
    cout<<q.a<<","<<q.b<<","<<q.c<<","<<q.d<<endl;
}


int main(){

    vec3D pos(1,2,3);
    vec3D axis(1,0,0);

    quaternions rotated_q = rotate(pos,axis,1.57);

    printQuar(rotated_q);

}