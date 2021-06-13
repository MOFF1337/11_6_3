#include <iostream>

bool is_string_correct(std::string str){
    int dot_counter = 0;
    for(int i = 0; i < str.length(); i++){
        int n = str[i] - '0';
        if(!(0 <= n && n <= 9)) return false;
        if(str[i] == '.') dot_counter++;
    }
    return dot_counter == 3;
}

std::string get_number(std::string ip, int index){
    for(int i = 0; i < index; i++){ //pre
        int pos = ip.find('.');
        if(pos == -1) break;
        ip = ip.erase(0, pos + 1);
    }
    for(int i = 0; i < 3 - index; i++){ //post
        int pos = ip.rfind('.');
        if(pos == -1) break;
        ip = ip.erase(pos);
    }
    return ip;
}

bool is_number_correct(std::string number_str){
    if(number_str == "") return false;
    int number_int = std::stoi(number_str);
    if(number_str[0] == '0'){
        if(number_int == 0 && number_str.length() == 1){
        } else return false;
    }
    return (0 <= number_int && number_int < 256);
}

int main() {
    std::string ip;
    std::cout << "Input the ip:" << std::endl;
    std::cin >> ip;

    for(int i = 0; i < 3; i++){
        if(!(is_string_correct(ip) && is_number_correct(get_number(ip,i)))){
            std::cout << "Wrong ip!" << std::endl;
            return 0;
        }
    }

    std::cout << "Correct ip!";
    return 0;
}
