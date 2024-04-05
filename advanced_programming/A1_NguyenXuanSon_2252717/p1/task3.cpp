#include <iostream>

int main() {
    // Personal information
    std::string name = "Nguyen Xuan Son";
    int age = 20;
    std::string location = "Ho Chi Minh City";
    std::string email = "son.nguyencsk22@hcmut.edu.vn";
    
    // ASCII art for decoration
    std::string border = "---------------------------------------------------------";
    std::string cloud = 
        "            _    .  ,   .           " "\n"
        "       *  / \\_ *  / \\_      _  *        " "\n"
        "         /   \\  /   \\  * / \\_         " "\n"
        "    _   /\\  /\\  /\\  /\\    /\\            " "\n"
        "  / \\_/  \\/  \\/  \\/  \\/\\_/  \\  *      " "\n"
        " /                           \\ /\\        " "\n"
        " \\        XuanSon             /  \\       " "\n"
        "  \\     Computer Science     /    \\ *   " "\n"
        "   \\                        /      \\    " "\n"
        "    \\   Age:20             /   *    \\ " "\n"
        "     \\____________________/___*______\\ " "\n";

    // Output the presentation
    std::cout << cloud << std::endl;
    std::cout << border << std::endl;
    std::cout << "  Name:      " << name << std::endl;
    std::cout << "  Age:       " << age << std::endl;
    std::cout << "  Location:  " << location << std::endl;
    std::cout << "  Email:     " << email << std::endl;
    std::cout << border << std::endl;

    return 0;
}
