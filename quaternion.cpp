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

struct quaternion{
    float a=0, b=0, c=0, d=0;
    quaternion(){}
    quaternion(float a, float b, float c, float d){
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
};

void printQuar(quaternion q, string s);
void printvec3D(vec3D p, string s);

quaternion conjugate(quaternion q){
    quaternion q_;
    q_.a = q.a;
    q_.b = 0 - q.b;
    q_.c = 0 - q.c;
    q_.d = 0 - q.d;
    return q_;
}

quaternion quartize(vec3D axis, float theta){
    quaternion q;
    q.a = cos(theta/2);
    // cout<<"theta = "<<theta<<endl;
    // cout<<"cos(theta/2) = "<<cos(theta/2)<<endl;
    
    q.b = sin(theta/2) * axis.x;
    q.c = sin(theta/2) * axis.y;
    q.d = sin(theta/2) * axis.z;
    return q;
}

quaternion mul(quaternion x, quaternion y){
    quaternion ans(0,0,0,0);
    ans.a = x.a * y.a  -  x.b * y.b  -  x.c * y.c  -  x.d * y.d  ;
    ans.b = x.a * y.b  +  x.b * y.a  +  x.c * y.d  -  x.d * y.c  ;
    ans.c = x.a * y.c  +  x.c * y.a  +  x.d * y.b  -  x.b * y.d  ;
    ans.d = x.a * y.d  +  x.d * y.a  +  x.b * y.c  -  x.c * y.b  ;
    return ans;
}

quaternion rotate(vec3D pos, vec3D axis, float theta){
    
    //normalize axis
    float scl = sqrt(pow(axis.x,2) + pow(axis.y,2) + pow(axis.z,2));
    axis.x /= scl; axis.y /= scl; axis.z /= scl;
    
    quaternion q = quartize(axis, theta);
    quaternion q_ =conjugate(q) ;
    quaternion v = quartize(pos, M_PI); //default theta = 180

    printQuar(q,"q");
    printQuar(q_,"q_");
    printQuar(v,"v");

    quaternion rotated_v = mul(mul(q,v),q_) ;
    return rotated_v ;
}

void printvec3D(vec3D p, string s){
    cout<<s<<" = "; 
    cout<<p.x<<", "<<p.y<<", "<<p.z<<endl;
}

void printQuar(quaternion q, string s){
    cout<<s<<" = "; 
    cout<<q.a<<", "<<q.b<<", "<<q.c<<", "<<q.d<<endl;
}

int main(){

    vec3D pos(1,2,3);
    vec3D axis(1,0,0);

    quaternion rotated_q = rotate(pos,axis,M_PI/2);
    printQuar(rotated_q, "rotated q");

}