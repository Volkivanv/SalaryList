#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
struct person{
    std::string name;
    std::string family;
    char c;
    int dd;
    int mm;
    int yy;
    double sum;
    std::string currency;
    std::string nl;
};

void readList(std::vector<person> &lst){
    std::ifstream salaryList;
    salaryList.open("SalaryList.txt");
    if(salaryList) {
        while (!salaryList.eof()) {
            person pers;
            salaryList >> pers.name;
            salaryList >> pers.family;
            if(pers.name.length() < 1) break;
            salaryList >> pers.dd;
            salaryList >> pers.c;
            salaryList >> pers.mm;
            salaryList >> pers.c;
            salaryList >> pers.yy;
            salaryList >> pers.sum;
            salaryList >> pers.currency;

            lst.push_back(pers);
        }

    } else {
        std::cerr << "File is not found!" <<std::endl;
    }
    salaryList.close();
}

void addPerson(std::vector<person> &lst, const std::string& inputString){
    person pers;
    std::stringstream text;

    text.str(inputString);
    text >> pers.name;
    text >> pers.family;
    text >> pers.dd;
    text >> pers.c;
    text >> pers.mm;
    text >> pers.c;
    text >> pers.yy;
    text >> pers.sum;

    pers.currency = " RUB";

    lst.push_back(pers);

}

void addPersToList(std::vector<person> &lst){
    std::ofstream salaryList("SalaryList.txt", std::ios::app);
    salaryList.setf(std::ios::fixed);
    salaryList.precision(2);
    if(salaryList) {
    while (true) {
        std::string inputString;

        std::cout << "Please, input 'Name Family DD.MM.YYYY SUM'. If you want exit input 'exit' " << std::endl;
        getline(std::cin, inputString);
        if (inputString == "exit") {
            break;
        }
        addPerson(lst, inputString);

        salaryList << lst.back().name << " " << lst.back().family << " " << lst.back().dd << lst.back().c <<
        lst.back().mm << lst.back().c << lst.back().yy << " " << lst.back().sum << lst.back().currency << std::endl;

    }
    } else {
        std::cerr << "File is not found!" <<std::endl;
    }
    salaryList.close();
}

int main() {
    std::vector<person> list;
    std::string command;
    std::getline(std::cin,command);
    if(command == "read"){
        readList(list);
        for(int i = 0; i < list.size(); i++){
            std::cout << list[i].name <<" " << list[i].family << " " << list[i].dd << list[i].c << list[i].mm <<
            list[i].c << list[i].yy << " " << list[i].sum << " " <<list[i].currency << std::endl;
        }
    }else if(command == "add") {
        readList(list);
        addPersToList(list);
    }

    return 0;
}
