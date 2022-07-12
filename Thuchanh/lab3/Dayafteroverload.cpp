#include <iostream>

class NextDay {
    private:
        int day, month, year;
        int dayofmonth;
        int range;
    public:
        NextDay()
        {
            day = month = year = 1;
        }

        bool leapyear()
        {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) return 1;
            return 0;
        }

        bool leapyear(int byear)
        {
            if ((byear % 4 == 0 && byear % 100 != 0) || (byear % 400 == 0)) return 1;
            return 0;
        }

        int DOM()
        {
            switch (month) {
                case 4: case 6: case 9: case 11:
                    dayofmonth = 30;
                    break;
                case 2:
                    if (leapyear()) dayofmonth = 29;
                    else dayofmonth = 28;
                    break;
                default:
                    dayofmonth = 31;
                    break;
            }

            return dayofmonth;
        }

        void standardised()
        {
            day = std::abs(day);
            month = std::abs(month);
            year = std::abs(year);
            month = month % 12;
            if (month == 0) month = 12;
            if (day > DOM()) {
                day = 1;
            }
        }

        void set()
        {
            std::cin >> day >> month >> year;
            standardised();
        }

        void InXDs()
        {
            int InD;
            std::cin >> InD;
            day += InD;
            while (day > DOM()) {
                day -= DOM();
                month++;
                if (month > 12) {
                    year++;
                    month -= 12;
                }
            }
        }

        void DeXDs()
        {
            int DeD;
            std::cin >> DeD;
            
            if (day >= DeD) day -= DeD;

            while (day < DeD) {
                month--;
                if (month == 0) {
                    month = 12;
                    year--;
                }
                day += DOM() - DeD;
            }   
        }

        int OrderOfYear()
        {
            int result = day;
            for (int i = 1; i < month; i++) {
                switch (i) {
                    case 4: case 6: case 9: case 11:
                        result += 30;
                        break;
                    case 2:
                        if (leapyear()) result += 29;
                        else result += 28;
                        break;
                    default:
                        result += 31;
                        break;
                }
            }
            return result;
        }

        int Range(NextDay *ND2)
        {
            if (ND2 -> year > this -> year) std::swap(*ND2, *this);
            int addDay = 0;

            for (int i = this -> year - 1; i >= ND2 -> year; i--) {
                if (leapyear(i)) addDay += 366;
                else addDay += 365;
            }

            int OOY1 = addDay + OrderOfYear();
            int OOY2 = ND2 -> OrderOfYear();

            return std::abs(OOY1 - OOY2);
        }

        void print()
        {
            std::cout << day << " " << month << " " << year << "\n";
        }
};

int main()
{
    NextDay *ND1 = new NextDay;
    NextDay *ND2 = new NextDay;
    ND1 -> set();

    int select;
    do {
        std::cin >> select;
        switch (select)
        {
            case 1:
                ND1 -> InXDs();
                break;
            case 2:
                ND1 -> DeXDs();
                break;
            case 3:
                ND2 -> set();
                std::cout << ND1 -> Range(ND2);
                exit(0);
                break;
        }
    }while(1);
}