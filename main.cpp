#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    std::string filePath = "SalaryList.txt";
    std::ofstream salaryList(filePath,std::ios::app);
    salaryList.setf(std::ios::fixed);
    salaryList.precision(2);
    while(true){
        std::string inputString;
        std::stringstream text;
        std::string name, family;
        char c;
        int dd, mm, yyyy;
        double sum;
        std::cout<<"Please, input 'Name Family DD.MM.YYYY SUM'. If you want exit input 'exit' " << std::endl;
        getline(std::cin,inputString);
        if(inputString ==  "exit") {
            break;
        }
        text.str(inputString);
        text >> name >> family >> dd >> c >> mm >> c >> yyyy >> sum;


        salaryList << name <<" "<< family <<" "<< dd <<"."<< mm << "." << yyyy << " " << sum <<" RUB" << std::endl;

    }
    salaryList.close();


    return 0;
}
