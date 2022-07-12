#include <iostream>

class CPU {
    protected:
        std::string cpuID, cpuOption, cpuBrand;
        int cpuPrice, cores;
        float cycle;
    public:
        void setCPU()
        {
            std::cin.ignore();
            std::getline(std::cin, cpuID);
        }

        int getCPUPrice()
        {
            return cpuPrice;
        }

        void printCPU()
        {
            std::cout << "CPU: " << cpuID
            << " " << cpuOption
            << " " << cpuBrand
            << " " << cores
            << " " << cycle
            << " " << cpuPrice << "\n";
        }
};

class Alpha : public CPU {
    public:
        Alpha()
        {
            cpuOption = "Alpha";
            cpuBrand = "Black";
            cpuPrice = 200;
            cores = 2;
            cycle = 1.8;
        }
};

class Beta : public CPU {
    public:
        Beta()
        {
            cpuOption = "Beta";
            cpuBrand = "Black";
            cpuPrice = 400;
            cores = 4;
            cycle = 2.46;
        }
};

class Gamma : public CPU {
    public:
        Gamma()
        {
            cpuOption = "Gamma";
            cpuBrand = "White";
            cpuPrice = 600;
            cores = 4;
            cycle = 2.6;
        }
};

class Case {
    protected:
        std::string caseID, caseOption, caseBrand, caseColor;
        int colorSelect, casePrice;
    public:
        virtual void setCase()
        {
            std::getline(std::cin, caseID);
            std::cin >> colorSelect;
        }

        int getColorSelect()
        {
            return colorSelect;
        }

        int getCasePrice()
        {
            return casePrice;
        }

        void printCase()
        {
            std::cout << "Case: " << caseID
                    << " " << caseOption
                    << " " << caseBrand
                    << " " << caseColor
                    << " " << casePrice << "\n";
        }
};

class Aluminum : public Case {
    public:
        Aluminum()
        {
            caseOption = "Nhom";
            caseBrand = "Black";
            casePrice = 400;
        }

        void setCase()
        {
            Case::setCase();
            if (getColorSelect() == 1) caseColor = "Do";
            else if (getColorSelect() == 2) caseColor = "Den";
        }
};

class Plastic : public Case {
    public:
        Plastic()
        {
            caseOption = "Nhua";
            caseBrand = "White";
            casePrice = 200;
        }

        void setCase()
        {
            Case::setCase();
            if (getColorSelect() == 1) caseColor = "Do";
            else if (getColorSelect() == 2) caseColor = "Den";
            else if (getColorSelect() == 3) caseColor = "Xanh";
        }
};

class Screen {
    protected:
        std::string screenID, screenBrand, resolution, antiGlareOption;
        int screenPrice;
        float size = 4.7;
    public:
        void setScreen()
        {
            std::getline(std::cin, screenID);
            std::getline(std::cin, screenBrand);
        }

        int getScreenPrice()
        {
            return screenPrice;
        }

        void setResolution(int resolutionSelect, bool antiGlare = 0)
        {
            if (resolutionSelect == 1) {
                resolution = "HD";
                screenPrice = 200;
            }

            else if (resolutionSelect == 2) {
                resolution = "FullHD";
                if (antiGlare == 1) {
                    screenPrice = 500;
                    antiGlareOption = "Chong Loa";
                }
                else screenPrice = 300;
            }
        }

        void printScreen()
        {
            std::cout << "Screen: " << screenID
                    << " " << screenBrand
                    << " " << resolution
                    << " " << screenPrice
                    << " " << antiGlareOption << "\n";
        }
};

class SmartPhone {
    protected:
        std::string phoneID, phoneOption;
        CPU *phoneCPU;
        Screen *phoneScreen;
        Case *phoneCase;
        float valueIndex;
        int cpuSelect, resolutionSelect, caseSelect;
        bool checkAntiGlare;
    public:
        virtual void setPhone()
        {
            std::cin >> phoneID;
            phoneCPU = new CPU;
            phoneScreen = new Screen;
            phoneCase = new Case;
        }

        float getPhonePrice()
        {
            return (float)(phoneCPU -> getCPUPrice() + phoneScreen -> getScreenPrice() + phoneCase -> getCasePrice()) * valueIndex;
        }

        void printPhone()
        {
            std::cout << "Phone: " << phoneID << " " << phoneOption << " " << getPhonePrice() << "\n";
            phoneCPU -> printCPU();
            phoneScreen -> printScreen();
            phoneCase -> printCase();
        }
};

class Venus : public SmartPhone {
    public:
        Venus()
        {
            phoneOption = "Venus";
            valueIndex = 1.3;
        }

        void setPhone()
        {
            SmartPhone::setPhone();
            std::cin >> cpuSelect;
            if (cpuSelect == 1) phoneCPU = new Alpha;
            else if (cpuSelect == 2) phoneCPU = new Beta;
            phoneCPU -> setCPU();

            phoneScreen -> setScreen();
            std::cin >> resolutionSelect;
            if (resolutionSelect == 1) phoneScreen -> setResolution(resolutionSelect);
            else {
                std::cin >> checkAntiGlare;
                phoneScreen -> setResolution(resolutionSelect, checkAntiGlare);
            }

            std::cin >> caseSelect;
            if (caseSelect == 1) phoneCase = new Aluminum;
            else if (caseSelect == 2) phoneCase = new Plastic;
            std::cin.ignore();
            phoneCase -> setCase();
        }
};

class Mars : public SmartPhone {
    public:
        Mars()
        {
            phoneOption = "Mars";
            valueIndex = 1.5;
        }

        void setPhone()
        {
            SmartPhone::setPhone();
            std::cin >> cpuSelect;
            if (cpuSelect == 1) phoneCPU = new Alpha;
            else if (cpuSelect == 2) phoneCPU = new Beta;
            else if (cpuSelect == 3) phoneCPU = new Gamma;
            phoneCPU -> setCPU();

            phoneScreen -> setScreen();
            std::cin >> checkAntiGlare;
            phoneScreen -> setResolution(2, checkAntiGlare);

            phoneCase = new Aluminum;
            std::cin.ignore();
            phoneCase -> setCase();
        }
};

class Jupiter : public SmartPhone {
    public:
        Jupiter()
        {
            phoneOption = "Jupiter";
            valueIndex = 1.8;
        }

        void setPhone()
        {
            SmartPhone::setPhone();
            phoneCPU = new Gamma;
            phoneCPU -> setCPU();

            phoneScreen -> setScreen();
            phoneScreen -> setResolution(2,true);

            phoneCase = new Aluminum;
            phoneCase -> setCase();
        }
};

class PhoneList {
    private:
        int n;
        SmartPhone **phoneList;
    public:
        void input()
        {
            std::cin >> n;
            phoneList = new SmartPhone *[n];
            int phoneSelect;
            for (int i = 0; i < n; i++) {
                std::cin >> phoneSelect;
                if (phoneSelect == 1) phoneList[i] = new Venus;
                else if (phoneSelect == 2) phoneList[i] = new Mars;
                else phoneList[i] = new Jupiter;
                phoneList[i]->setPhone();
            }
        }

        void output()
        {
            for (int i = 0; i < n; i++) {
                phoneList[i] -> printPhone();
            }
        }
};

int main()
{
    PhoneList List;
    List.input();
    List.output();
    return 0;
}