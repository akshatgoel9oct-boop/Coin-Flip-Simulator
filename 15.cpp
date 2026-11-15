#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

// Text Colors
#define RESET     "\033[0m"
#define YELLOW    "\033[1;33m"
#define GREEN     "\033[1;32m"
#define RED       "\033[1;31m"
#define CYAN      "\033[1;36m"

// Background Color Banners (Format: \033[STYLE;TEXT;BACKGROUNDm)
#define BLUE_BG   "\033[1;37;44m" // White text on Blue background
#define GREEN_BG  "\033[1;30;42m" // Black text on Green background
#define RED_BG    "\033[1;37;41m" // White text on Red background
#define YELLOW_BG "\033[1;30;43m" // Black text on Yellow background

void showCoinAnimation(int result);

class coinflipd {
    int heads, tails;
    int streak = 0;

public:
    void getdata(int a) {
        heads = a;
        tails = a - 1;
    }

    void backend() {
        int c = (rand() % 2) + 1;

        showCoinAnimation(c);

        if (heads == 1) {
            cout << CYAN << "You have chosen: Heads\n" << RESET;
        } else {
            cout << CYAN << "You have chosen: Tails\n" << RESET;
        }

        bool won = false;
        if (c == 1) {
            cout << "The coin landed on: " << YELLOW << "Heads\n\n" << RESET;
            if (heads == 1) won = true;
        } else {
            cout << "The coin landed on: " << YELLOW << "Tails\n\n" << RESET;
            if (tails == 1) won = true;
        }

        if (won) {
            cout << GREEN_BG << "  ★ YOU HAVE WON THE GAME! ★  " << RESET << "\n\n";
            streak += 1;
            cout << GREEN << "Your winning streak is: " << streak << "\n" << RESET;
        } else {
            cout << RED_BG << "  ✖ YOU HAVE LOST THE GAME! ✖  " << RESET << "\n\n";
            streak = 0;
            cout << RED << "Your winning streak is: " << streak << "\n" << RESET;
        }
    }
};

int main() {
    srand(time(0));
    int a;
    int stop = 0;
    coinflipd cf;

    // Welcome Banner with Blue Background
    cout << BLUE_BG << "========================================" << RESET << "\n";
    cout << BLUE_BG << "    Welcome to the Coin Flip Simulator  " << RESET << "\n";
    cout << BLUE_BG << "========================================" << RESET << "\n";

    while (true) {
        cout << CYAN << "\nWhat do you want to choose? 1. Heads or 2. Tails\n" << RESET;
        cin >> a;

        cf.getdata(a);
        cf.backend();

        cout << CYAN << "\nDo you want to continue playing? 1. Yes or 2. No\n" << RESET;
        cin >> stop;

        if (stop == 2) {
            cout << "\n" << YELLOW_BG << " Thank you for playing! Come back again! " << RESET << "\n";
            break;
        } else if (stop == 1) {
            system("cls");
            cout << BLUE_BG << "          --- NEXT ROUND ---          " << RESET << "\n";
        }
    }

    return 0;
}

// Graphics & Animation at the very end
void showCoinAnimation(int result) {
    string frames[] = {
        "   _______   \n  /       \\  \n |  HEADS  | \n  \\_______/  ",
        "     ___     \n    /   \\    \n   |  |  |   \n    \\___/    ",
        "   _______   \n  /       \\  \n |  TAILS  | \n  \\_______/  ",
        "     ___     \n    /   \\    \n   |  |  |   \n    \\___/    "
    };

    for (int i = 0; i < 8; i++) {
        system("cls");
        cout << CYAN << "\nFlipping the coin...\n\n" << RESET;
        cout << YELLOW << frames[i % 4] << "\n" << RESET;
        Sleep(150);
    }

    system("cls");
    cout << "\n" << YELLOW;
    if (result == 1) {
        cout << "   _______   \n";
        cout << "  /       \\  \n";
        cout << " |  HEADS  | \n";
        cout << "  \\_______/  \n\n";
    } else {
        cout << "   _______   \n";
        cout << "  /       \\  \n";
        cout << " |  TAILS  | \n";
        cout << "  \\_______/  \n\n";
    }
    cout << RESET;
}
