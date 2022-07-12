#include <iostream>
using namespace std;
#include <string>

class CPU {
    protected:
        string cpuID, cpuOption;
        int cpuPrice;
    public:
        void setCPU(int cpuSelect)
        {
            getline(cin, cpuID);
            if (cpuSelect == 1) {
                cpuOption = "Core i3";
                cpuPrice = 100;
            }

            else if (cpuSelect == 2) {
                cpuOption = "Core i5";
                cpuPrice = 200;
            }

            else {
                cpuOption = "Core i7";
                cpuPrice = 300;
            }
        }

        int getCPUPrice()
        {
            return cpuPrice;
        }

        void printCPU()
        {
            cout << "CPU: " << cpuID << " " << cpuOption << " " << cpuPrice << "\n";
        }
};

class RAM {
    protected:
        string ramID, ramOption;
        int ramPrice, ramTotalPrice = 0;
    public:
        void setRAM(int ramSelect, int ramCapacity)
        {
            getline(cin, ramID);
            if (ramSelect == 1) {
                ramOption = "DDR3";
                ramPrice = 100;
            }

            else if (ramSelect == 2) {
                ramOption = "DDR4";
                ramPrice = 200;
            }
            ramTotalPrice = ramCapacity * ramPrice;
        }

        int getRAMTotalPrice()
        {
            return ramTotalPrice;
        }

        void printRAM()
        {
            cout << ramID << " ";
        }
};

class Monitor {
    public:
        string monitorID, monitorOption, resolution, standardOption;
        int monitorPrice;
    public:
        void setMonitor(int monitorSelect, int standard = 0)
        {
            getline(cin, monitorID);
            if (monitorSelect == 1) {
                monitorOption = "Mirror";
                monitorPrice = 1000;
                resolution = "HD";
            }

            else {
                resolution = "FullHD";
                monitorOption = "AntiGlare";
                if (standard == 1) {
                    monitorPrice = 2000;
                    standardOption = "Standard 1";
                }
                else if (standard == 2) {
                    monitorPrice = 3000;
                    standardOption = "Standard 2";
                }
                else if (standard == 3) {
                    monitorPrice = 4000;
                    standardOption = "Standard 1";
                }
            }
        }

        int getMonitorPrice()
        {
            return monitorPrice;
        }

        void printMonitor()
        {
            cout << "Monitor: " << monitorID
                << " " << monitorOption 
                << " " << resolution
                << " " << standardOption
                << " " << monitorPrice << "\n";
        }
};

class Hardware {
    protected:
        string hardwareID, hardwareOption;
        int hardwarePrice, hardwareCapacity;
    public:
        virtual void setHardware()
        {
            getline(cin, hardwareID);
            cin >> hardwareCapacity >> hardwarePrice;
        }

        int getHardwarePrice()
        {
            return hardwarePrice;
        }

        virtual void printHardware()
        {
            cout << "Hardware: " << hardwareID
                << " " << hardwareOption
                << " " << hardwareCapacity
                << " " << hardwarePrice;
        }
};

class HDD : public Hardware {
    protected:
        int rotations;
    public:
        HDD()
        {
            hardwareOption = "HDD";
        }

        void setHardware()
        {
            Hardware::setHardware();
            cin >> rotations;
        }

        void printHardware()
        {
            Hardware::printHardware();
            cout << " " << rotations << "\n";
        }
};

class SSD : public Hardware {
    protected:
        int readSpeed, writeSpeed;
    public:
        SSD()
        {
            hardwareOption = "SSD";
        }

        void setHardware()
        {
            Hardware::setHardware();
            cin >> readSpeed >> writeSpeed;
        }

        void printHardware()
        {
            Hardware::printHardware();
            cout << " " << readSpeed
                << " " << writeSpeed << "\n";
        }
};

class Product {
    protected:
        string productID, productName, productOption, RAMOption;
        CPU *usingCPU;
        Hardware *usingHardware;
        Monitor *usingMonitor;
        RAM **RAMList;
        int hardwareSelect, antiGlareStandard, cpuSelect, RAMQuantity, RAMCapacity, RAMSelect, RAMPrice = 0;
    public:
        virtual void setProduct()
        {
            cin.ignore();
            getline(cin, productID);
            getline(cin, productName);
            usingCPU = new CPU;
            usingHardware = new Hardware;
            usingMonitor = new Monitor;
        }

        int getProductPrice()
        {
            return RAMPrice + usingCPU->getCPUPrice() + usingHardware->getHardwarePrice() + usingMonitor->getMonitorPrice();
        }

        string getRAMOption()
        {
            return RAMOption;
        }

        void printProduct()
        {
            cout << "Product: " << productID
                << " " << productOption
                << " " << productName
                << " " << getProductPrice() << "\n";
            usingCPU -> printCPU();

            cout << "RAM: ";
            for (int i = 0; i < RAMQuantity; i++) {
                RAMList[i] -> printRAM();
            }

            cout << getRAMOption()
                    << " " << RAMCapacity 
                    << " " << RAMPrice << "\n";

            usingMonitor->printMonitor();
            usingHardware->printHardware();
        }
};

class Butterfly : public Product {
    public:
        Butterfly()
        {
            productOption = "Butterfly";
        }

        void setProduct()
        {
            Product::setProduct();
            usingCPU -> setCPU(3);

            cin >> RAMQuantity;
            cin >> RAMSelect;
            if (RAMSelect == 1) RAMOption = "DDR3";
            else RAMOption = "DDR4";
            cin >> RAMCapacity;
            RAMList = new RAM *[RAMQuantity];
            cin.ignore();
            for (int i = 0; i < RAMQuantity; i++) {
                RAMList[i] = new RAM;
                RAMList[i] -> setRAM(RAMSelect, RAMQuantity);
                RAMPrice += RAMList[i] -> getRAMTotalPrice();
            }

            cin >> antiGlareStandard;
            cin.ignore();
            usingMonitor -> setMonitor(2, antiGlareStandard);

            usingHardware = new SSD;
            usingHardware -> setHardware();
        }
};

class Fly : public Product {
    public:
        Fly()
        {
            productOption = "Fly";
        }

        void setProduct()
        {
            Product::setProduct();

            usingCPU -> setCPU(2);

            cin >> RAMQuantity;
            cin >> RAMSelect;
            if (RAMSelect == 1) RAMOption = "DDR3";
            else RAMOption == "DDR4";
            cin >> RAMCapacity;
            RAMList = new RAM *[RAMQuantity];
            cin.ignore();
            for (int i = 0; i < RAMQuantity; i++) {
                RAMList[i] = new RAM;
                RAMList[i] -> setRAM(RAMSelect, RAMQuantity);
                RAMPrice += RAMList[i] -> getRAMTotalPrice();
            }

            usingMonitor -> setMonitor(1);

            cin >> hardwareSelect;
            if (hardwareSelect == 1) usingHardware = new HDD;
            else usingHardware = new SSD;
            usingHardware -> setHardware();
        }
};

class Bee : public Product {
    public:
        Bee()
        {
            productOption = "Bee";
        }

        void setProduct()
        {
            Product::setProduct();

            do {
                cin >> cpuSelect;
            } while (cpuSelect != 1 && cpuSelect != 2);

            usingCPU -> setCPU(cpuSelect);

            cin >> RAMQuantity;
            cin >> RAMSelect;
            if (RAMSelect == 1) RAMOption = "DDR3";
            else RAMOption == "DDR4";
            cin >> RAMCapacity;
            RAMList = new RAM *[RAMQuantity];
            cin.ignore();
            for (int i = 0; i < RAMQuantity; i++) {
                RAMList[i] = new RAM;
                RAMList[i] -> setRAM(RAMSelect, RAMQuantity);
                RAMPrice += RAMList[i] -> getRAMTotalPrice();
            }

            usingMonitor -> setMonitor(1);

            cin >> hardwareSelect;
            if (hardwareSelect == 1) usingHardware = new HDD;
            else usingHardware = new SSD;
            usingHardware -> setHardware();
        }
};

class Order {
    protected:
        int n, productSelect;
        Product **productList;
    public:
        void set()
        {
            cin >> n;
            productList = new Product *[n];

            for (int i = 0; i < n; i++) {
                cin >> productSelect;
                if (productSelect == 1) productList[i] = new Butterfly;
                else if (productSelect == 2) productList[i] = new Fly;
                else productList[i] = new Bee;
                productList[i]->setProduct();
            }
        }

        void print()
        {
            for (int i = 0; i <n; i++) {
                productList[i]->printProduct();
            }
        }
};

int main()
{
    Order List;
    List.set();
    List.print();
    return 0;
}