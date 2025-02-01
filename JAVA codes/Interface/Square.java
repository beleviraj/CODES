interface Shape
{
    double calculatearea();
    double calculateperimeter();
}

class Circle implements Shape
{
    private double r;

    Circle(double radius)
    {
        r=radius;
    }
    public double calculatearea()
    {
        double area=3.142*r*r;
        return area;
    }

    public double calculateperimeter()
    {
        double perimeter=2*3.142*r;
        return perimeter;
    }
}

class Rectangle implements Shape
{
    private double b;
    private double l;

    Rectangle(double length,double breadth)
    {
        b=breadth;
        l=length;
    }
    
    public double calculatearea()
    {
        double area=l*b;
        return area;
    }

    public double calculateperimeter()
    {
        double perimeter=2*(l+b);
        return perimeter;
    }
    
}

class Square implements Shape
{
    private double s;
    Square(double side)
    {
        s=side;
    }
    public double calculatearea()
    {
        double area=s*s;
        return area;
    }

    public double calculateperimeter()
    {
        double perimeter=2*s;
        return perimeter;
    }

    public static void main(String args[])
    {   System.out.println("-----------------------------------------------------");
        Circle c=new Circle(4);
        System.out.println("Area of Circle is: "+c.calculatearea()+"\n Perimeter of Circle is: "+c.calculateperimeter());
        System.out.println("-----------------------------------------------------");
        Rectangle R=new Rectangle(4,5);
        System.out.println("Area of Rectangle is: "+R.calculatearea()+"\n Perimeter of Rectangle is: "+R.calculateperimeter());
        System.out.println("-----------------------------------------------------");
        Square S=new Square(4);
        System.out.println("Area of Square is: "+S.calculatearea()+"\n Perimeter of Square is: "+S.calculateperimeter());
        System.out.println("-----------------------------------------------------");
    }
}
