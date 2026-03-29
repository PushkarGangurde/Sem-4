// AREA OF SHAPES

#include<iostream> 
using namespace std;

class Area{
    int s,l,b,r,h;
public:
    void square();
    void rectangle();
    void triangle();
    void circle();
    void sphere();
    void cylinder();
};

void Area::square(){
    cout << "Side : ";
    cin >> s;
    cout << "Area of Square : " << s*s << endl;
}

void Area::rectangle(){
    cout << "Length : ";
    cin >> l;
    cout << "Breadth : ";
    cin >> b;
    cout << "Area of Rectangle : " << l*b << endl;
}

void Area::triangle(){
    cout << "Base : ";
    cin >> b;
    cout << "Height : ";
    cin >> h;
    cout << "Area of Triangle : " << 0.5*b*h << endl;
}

void Area::circle(){
    cout << "Radius : ";
    cin >> r;
    cout << "Area of Circle : " << 3.14*r*r << endl;
}

void Area::sphere(){
    cout << "Radius : ";
    cin >> r;
    cout << "Area of Sphere : " << 4*3.14*r*r << endl;
}

void Area::cylinder(){
    cout << "Radius : ";
    cin >> r;
    cout << "Height : ";
    cin >> h;
    cout << "Area of Cylinder : " << 2*3.14*r*(r+h) << endl;
}


int main(){
    int choice;

    Area a;
    while (true) {
        cout << "Area of :\n" << "1.Square\n" << "2.Rectangle\n" << "3.Triangle\n" << "4.Circle\n" << "5.Sphere\n" << "6.Cylinder\n" << "7.Exit" <<endl;
        cout << "\nenter choice : ";
        cin >> choice;

        switch(choice) {
            case 1:
                a.square();
                break;

            case 2:
                a.rectangle();
                break;

            case 3:
                a.triangle();
                break;

            case 4:
                a.circle();
                break;

            case 5:
                a.sphere();
                break;

            case 6:
                a.cylinder();
                break;

            case 7:
                cout << "Exiting..." << endl;
                return 0;
                
            default:
                cout << "Invalid Choice" << endl;
                break;
        }
    }


    return 0;
}