#include <iostream>

int main(int argc, char *argv[]) {
    while (true)
    {
        std::cout << "1: Print help" << std::endl;
        std::cout << "2: Print exchange" << std::endl;
        std::cout << "3: Place an ask" << std::endl;
        std::cout << "4: Place a bid" << std::endl;
        std::cout << "5: Print wallet" << std::endl;
        std::cout << "6: Continue" << std::endl;

        int userOption;
        std::cout << "Type in 1-6" << std::endl;
        std::cin >> userOption;

        switch (userOption)
        {
        case 1:
            std::cout << "Help - choose options from the menu" << std::endl;
            std::cout << "and follow the on screen instructions" << std::endl;
            break;
        case 2:
            std::cout << "Looking good there" << std::endl;
            break;
        case 3:
            std::cout << "Make an offer" << std::endl;
            break;
        case 4:
            std::cout << "Make a bid" << std::endl;
            break;
        case 5:
            std::cout << "Some amount of money" << std::endl;
            break;
        case 6:
            std::cout << "Doing financial things in the background" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Choose 1-6" << std::endl;
            break;
        }
    }
    return 0;
}