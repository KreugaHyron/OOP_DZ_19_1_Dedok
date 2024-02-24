#include <iostream>
#include <string>
using namespace std;
class Processor {
private:
    string model;
public:
    Processor(string m) : model(m) {}
    string getModel() { return model; }
};

class RAM {
private:
    int sizeGB;
public:
    RAM(int s) : sizeGB(s) {}
    int getSize() { return sizeGB; }
};

class Mouse {
private:
    string brand;
public:
    Mouse(string b) : brand(b) {}
    string getBrand() { return brand; }
};

class Webcam {
private:
    string resolution;
public:
    Webcam(string r) : resolution(r) {}
    string getResolution() { return resolution; }
};

class Printer {
private:
    string type;
public:
    Printer(string t) : type(t) {}
    string getType() { return type; }
};

class GraphicsCard {
private:
    string model;
public:
    GraphicsCard(string m) : model(m) {}
    string getModel() { return model; }
};
class Laptop {
private:
    Processor processor;
    RAM ram;
    Mouse mouse;
    Webcam webcam;
    Printer* printer;
    GraphicsCard* graphicsCard; 
public:
    Laptop(Processor p, RAM r, Mouse m, Webcam w, Printer* prt, GraphicsCard* gc)
        : processor(p), ram(r), mouse(m), webcam(w), printer(prt), graphicsCard(gc) {}

    void printSpecs() {
        cout << "Processor: " << processor.getModel() << endl;
        cout << "RAM size: " << ram.getSize() << "GB" << endl;
        cout << "Mouse brand: " << mouse.getBrand() << endl;
        cout << "Webcam resolution: " << webcam.getResolution() << endl;
        if (printer)
            cout << "Printer type: " << printer->getType() << endl;
        if (graphicsCard)
            cout << "Graphics card model: " << graphicsCard->getModel() << endl;
    }
};
int main()
{
    Processor intelCorei7("Intel Core i7");
    RAM memory(16);
    Mouse logitech("Logitech");
    Webcam hd("1080p");
    Printer inkjet("Inkjet");
    GraphicsCard nvidiaGTX("Nvidia GTX 1650");

    Laptop myLaptop(intelCorei7, memory, logitech, hd, &inkjet, &nvidiaGTX);
    myLaptop.printSpecs();
    return 0;
}

