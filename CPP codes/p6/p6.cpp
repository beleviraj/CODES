#include<iostream>
#include<cmath>
using namespace std;
class circle{
    private:
    int centerx,centery,radius;
    float circum,area;
    public:
    circle()
    {
        centerx=0;
        centery=0;
        radius=0;
    }
    circle(int cx, int cy)
    {
        centerx=cx;
        centery=cy;
        radius=0;
    }
    circle(int cx,int cy,int r)
    {
        centerx=cx;
        centery=cy;
        radius=r;
    }

    void calarea()
    {
        area=3.14*radius*radius;
    }
    
    float getarea()
    {
        return area;
    }

    void calcircum()
    {
        circum=2*3.14*radius;
    }

    float getcircum()
    {
        return circum;
    }

    void istangent(int cx,int cy,float radius,int x1,int y1,int x2,int y2)
		{
			float dis;
			dis=abs((cx-x1)*(y2-y1)-(cy-y1)*(x2-x1))/sqrt(pow(x2-x1,2)+pow(y2-y1,2));
			cout<<"\nDis="<<dis<<endl;
			
			if(radius==dis)
			{
				cout<<"Line is tangent to the Circle."<<endl;
			}
			else
			{
				cout<<"Line is NOT tangent to the circle."<<endl;
			}
		}

    
};

class line{
    private:
    int x1,x2,y1,y2;
    float slope,intercept; 
    public:
    line()
    {
        x1=0,x2=0,y1=0,y2=0;
    }

    line(int X1,int Y1,int X2,int Y2)
    {
        x1=X1,x2=X2,y1=Y1,y2=Y2;
    }
    void calslopeandintercept()
    {
        slope=(y2-y1)/(x2-x1);
        intercept=y1-(slope*x1);
        cout<<"SLOPE is: "<<slope<<endl;
        cout<<"INTERCEPT is: "<<intercept<<endl;
    }

};
int main(){




    return 0;
}