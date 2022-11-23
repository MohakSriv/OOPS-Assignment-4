//Assignment 4:
//Written by: Mohak Kumar Srivastava
//Roll Number:2105631 Section CSE-23

// A program to that uses inheritance,file handling,operator overloading,exception handling,runtime polymorphism,templates


#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;
template <class T>
void print_succes(T data)
{
    cout<<"The program exited succesfully with code:"<<data<<endl;
}
class vehicle
{
private:
    int mileage;
    int price;

public:
    vehicle();
    void getdata();
    void display();
};
class car : public vehicle
{
private:
    int owncost;
    int warranty;
    int seatingcap;
    string fueltype;

public:
    car();
    void getdata();
    void display();
};
class bike : public vehicle
{
private:
    int nocylinders;
    int nogears;
    int fueltank;
    string coolingtype;
    string wheeltype;

public:
    bike();
    void getdata();
    void display();
};
class audi : public car
{
private:
    string maketype;

public:
    audi();
    friend ostream& operator<<(ostream& p, audi);
    void getdata();
    void display();
};
class ford : public car
{
private:
    string maketype;

public:
    ford();
    friend ostream& operator<<(ostream& p, ford);
    void getdata();
    void display();
};
class bajaj : public bike
{
private:
    string maketype;

public:
    bajaj();
    friend ostream& operator<<(ostream& p, bajaj);
    void getdata();
    void display();
};
class TVS : public bike
{
private:
    string maketype;

public:
    TVS();
    friend ostream& operator<<(ostream& p,TVS);
    void getdata();
    void display();
};
vehicle::vehicle() // vehicle class declarations
{
    mileage = 0;
    price = 0;
}
void vehicle::getdata()
{   int m,p;
    cout << "Enter the mileage:";
    cin >> m;
    cout << "Enter the price :";
    cin >> p;
    try{
        if(price<0)
        {
            throw 1;
        }
        else
            mileage=m;
            price=p;
    }
    catch(int)
    {
        cout<<"The price cannot be negative\n";
    }
}
void vehicle::display()
{
    cout << "Milage:" << mileage << endl;
    cout << "Price:" << price << endl;
}
car::car() // car class declarations
{
    vehicle();
    owncost = 0;
    warranty = 0;
    seatingcap = 0;
    fueltype = "Petrol";
}
void car::getdata()
{
    vehicle::getdata();
    string ftype;
    cout << "Enter the ownership cost:";
    cin >> owncost;
    cout << "Enter the warranty in years:";
    cin >> warranty;
    cout << "Enter the seating capacity:";
    cin >> seatingcap;
    cout << "Enter the fuel type:";
    getline(cin >> ws, fueltype);
}
void car::display()
{
    vehicle::display();
    cout << "Ownership cost:" << owncost << endl;
    cout << "Warranty:" << warranty << endl;
    cout << "Seating Capacity:" << seatingcap << endl;
    cout << "Fuel type:" << fueltype << endl;
}

bike::bike() // bike classs declarations
{
    vehicle();
    nocylinders = 0;
    nogears = 0;
    fueltank = 0;
    coolingtype = "air";
    wheeltype = "alloy";
}
void bike::getdata()
{
    vehicle::getdata();
    string cootype, wheetype;
    cout << "Enter the number of cylinders:";
    cin >> nocylinders;
    cout << "Enter the number of gears:";
    cin >> nogears;
    cout << "Enter the size of the fueltank in inches:";
    cin >> fueltank;
    cout << "Enter the cooling type:";
    getline(cin >> ws, coolingtype);
    cout << "Enter the wheeltype:";
    getline(cin >> ws, wheeltype);
}
void bike::display()
{
    vehicle::display();
    cout << "Number of cylinders:" << nocylinders << endl;
    cout << "Number of gears:" << nogears << endl;
    cout << "Size of fueltank:" << fueltank << endl;
    cout << "Coolintype:" << coolingtype << endl;
    cout << "Wheel types:" << wheeltype << endl;
}
audi::audi()
{
    car();
    maketype = "R8";
}
void audi::getdata()
{
    car::getdata();
    cout << "Enter the maketype:";
    getline(cin >> ws, maketype);
}
void audi::display()
{
    car::display();
    cout << "Maketype:" << maketype << endl;
}
ostream& operator<<(ostream& p, audi ob)
{
    ob.display();
}
ford::ford()
{
    car();
    maketype = "endeavor";
}
void ford::getdata()
{
    car::getdata();

    cout << "Enter the maketype:";
    getline(cin >> ws, maketype);
};
void ford::display()
{
    car::display();
    cout << "Maketype:" << maketype << endl;
}
ostream& operator<<(ostream& p, ford ob)
{
    ob.display();
}
bajaj::bajaj()
{
    bike();
    maketype = "splendor";
}
void bajaj::getdata()
{
    bike::getdata();
    cout << "Enter the maketype:";
    getline(cin >> ws, maketype);
}

void bajaj::display()
{
    bike::display();
    cout << "Maketype:" << maketype << endl;
}
ostream& operator<<(ostream& p, bajaj ob)
{
    ob.display();
}
TVS::TVS()
{
    bike();
    maketype = "RR310";
}
void TVS::getdata()
{
    bike::getdata();
    cout << "Enter the maketype:";
    getline(cin >> ws, maketype);
}
void TVS::display()
{
    bike::display();
    cout << "Maketype:" << maketype << endl;
}
ostream& operator<<(ostream& p, TVS ob)
{
    ob.display();
}

int main()
{   vehicle v1;
    vehicle * bptr;
    audi a1;
    TVS rr310;
    ford endeavor;
    bajaj splendor;
    cout << "Creating an object of audi class, initialising it and displaying it:" << endl;
    bptr=&a1;
    ((audi*)&bptr)->getdata();
    ofstream file_obj1;
    file_obj1.open("Input.txt", ios::app);
    file_obj1.write((char *)&a1, sizeof(a1));
    file_obj1.close();
    cout<<a1;
    cout << "Creating an object of ford class, initialising it and displaying it:" << endl;
    endeavor.getdata();
    ofstream file_obj2;
    file_obj2.open("Input.txt", ios::app);
    file_obj2.write((char *)&endeavor, sizeof(endeavor));
    file_obj2.close();
    cout<<endeavor;
    cout << "Creating an object of Bajaj class, initialising it and displaying it:" << endl;
    splendor.getdata();
    ofstream file_obj3;
    file_obj3.open("Input.txt", ios::app);
    file_obj3.write((char *)&splendor, sizeof(splendor));
    file_obj3.close();
    cout<<splendor;
    cout << "Creating an object of TVS class, initialising it and displaying it:" << endl;
    rr310.getdata();
    ofstream file_obj4;
    file_obj4.open("Input.txt", ios::app);
    file_obj4.write((char *)&rr310, sizeof(rr310));
    file_obj4.close();
    cout<<rr310;
    print_succes<int>(0);
    return 0;
}