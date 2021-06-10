#include <iostream>

bool is_in_range(int number){
    if(0 <= number && number <= 255) return true;
    else return false;
}

bool is_dot_correct(std::string str){
    if(str[0] == '.' || str[str.length()-1] == '.') return false;
    for(int i = 1; i < str.length(); i++){
        if(str[i] == '.' && str[i-1] == '.') return false;
    }
    return true;
}

bool is_ip_correct(std::string ip){
    for(int i = 0; i < ip.length(); i++){
        if(ip[i] != '.' && '9' < ip[i] || ip[i] != '.' && ip[i] < '0') return false;
    }
    for(int i = 1; i < ip.length(); i++){
        if(!is_in_range(std::stoi(ip.substr(ip.rfind('.') + 1)))) return false;
        ip.erase(ip.rfind('.'));
    }
    return true;
}

bool is_zero_correct(std::string str){
    for(int i = 1; i < str.length(); i++){
        if(str[i] == '.' && str[i+1] == '0' && str[i+2] != '.') return false;
    }
    return true;
}

int main() {
    std::string ip;
    std::cout << "Input your ip:" << std::endl;
    std::cin >> ip;
    std::cout << (( is_dot_correct(ip) && is_ip_correct(ip) && is_zero_correct(ip))  ? "Yes" : "No");
}
