#include <iostream>
using namespace std;

class Rectangle
{
protected:
    int width;
    int height;

public:
    Rectangle() {}
    Rectangle(int width, int height)
    {
        this->width = width;
        this->height = height;
    }
    int getArea()
    {
        return width * height;
    }
};

void getInfo(Rectangle **&rec, int numOfRec)
{
    rec = new Rectangle *[numOfRec];
    for (int i = 0; i < numOfRec; i++)
    {
        int wid;
        int hei;
        cout << "Input width and height for rectangle " << i + 1 << ": " << endl;
        cout << "Width: ";
        cin >> wid;
        cout << "Height: ";
        cin >> hei;
        Rectangle *rectangle = new Rectangle(wid, hei);
        rec[i] = rectangle;
    }
}

void printInfo(Rectangle **rec, int numOfRec)
{
    for (int i = 0; i < numOfRec; i++)
    {
        cout << "The area of rectangle " << i + 1 << ": " << rec[i]->getArea() << endl;
    }
}

int main()
{
    int numOfRec;
    Rectangle **rec;
    cout << "How many rectangle? ";
    cin >> numOfRec;
    if (numOfRec < 1 || numOfRec > 100)
    {
        cout << "Out of Range";
        exit(1);
    }
    getInfo(rec, numOfRec);
    printInfo(rec, numOfRec);
    for (int i = 0; i < numOfRec; i++)
    {
        delete rec[i];
    }
}