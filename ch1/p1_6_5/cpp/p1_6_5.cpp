/*
 * Graphical Editor [ID: 10267]
 * */

#include <iostream>
#include <string>

#define MAX 250

#define NEW 'I'
#define CLEAR 'C'
#define SETC 'L'
#define DRAWV 'V'
#define DRAWH 'H'
#define DRAWR 'K'
#define FILL 'F'
#define STORE 'S'
#define EXIT 'X'

struct Size {
    int m;  // columns
    int n;  // rows
    Size() : m(0), n(0) {}
    Size(int mi, int ni) : m(mi), n(ni) {}
};

typedef Size Coord;

void constrainDim(Coord& p, Size& s) {
    if (p.m < 1)
        p.m = 1;
    else if (p.m > s.m)
        p.m = s.m;

    if (p.n < 1)
        p.n = 1;
    else if (p.n > s.n)
        p.n = s.n;
}

void cmdClear(char* image, Size& s) {
    for (int i = 0; i < s.n; i++)
        for (int j = 0; j < s.m; j++) *((image + i * s.m) + j) = 'O';
}

void cmdSetColor(char* image, Size& s, Coord& p, char& c) {
    if (p.m > 0 && p.m <= s.m && p.n > 0 && p.n <= s.n) {
        *((image + (p.n - 1) * s.m) + (p.m - 1)) = c;
    }
}

void cmdDrawRect(char* image, Size& s, Coord& p1, Coord& p2, char c) {
    // restrict dimensions
    constrainDim(p1, s);
    constrainDim(p2, s);

    if (p1.m > p2.m) {  // swap
        int t = p1.m;
        p1.m = p2.m;
        p2.m = t;
    }
    if (p1.n > p2.n) {  // swap
        int t = p1.n;
        p1.n = p2.n;
        p2.n = t;
    }

    for (int i = p1.n - 1; i < p2.n; i++)
        for (int j = p1.m - 1; j < p2.m; j++) *((image + i * s.m) + j) = c;
}

void cmdFill(char* image, Size& s, Coord& p, char old_col, char new_col) {
    if (p.n == 0 || p.m == 0 || p.n > s.n || p.m > s.m)
        return;  // return if coords out of image

    if (*((image + (p.n - 1) * s.m) + (p.m - 1)) != old_col)
        return;  // return if cell's color !=old_col

    *((image + (p.n - 1) * s.m) + (p.m - 1)) = new_col;  // set cell's new color

    // Up
    Coord up{p.m, p.n - 1};
    cmdFill(image, s, up, old_col, new_col);

    // Left
    Coord left{p.m - 1, p.n};
    cmdFill(image, s, left, old_col, new_col);

    // Down
    Coord down{p.m, p.n + 1};
    cmdFill(image, s, down, old_col, new_col);

    // Right
    Coord right{p.m + 1, p.n};
    cmdFill(image, s, right, old_col, new_col);

    return;
}

void cmdStore(char* image, Size& s, std::string& name) {
    std::cout << name << std::endl;

    for (int i = 0; i < s.n; i++) {
        for (int j = 0; j < s.m; j++) std::cout << *((image + i * s.m) + j);
        std::cout << std::endl;
    }
}

int main() {
    char image[MAX * MAX];  // stores the image (MAX x MAX)
    Size s;                 // size of the current image

    Coord p1, p2;
    char c, old_c;
    std::string name;
    bool run = true;
    while (run) {
        switch (char cmd = std::cin.get()) {
            case NEW:
                std::cin >> s.m >> s.n;
                std::cin.get();  // skip nl
                cmdClear((char*)image, s);
                break;

            case CLEAR:
                std::cin.get();  // skip nl
                cmdClear((char*)image, s);
                break;

            case SETC:
                std::cin >> p1.m >> p1.n >> c;
                std::cin.get();  // skip nl
                cmdSetColor((char*)image, s, p1, (char&)c);
                break;

            case DRAWV:
                std::cin >> p1.m >> p1.n >> p2.n >> c;
                std::cin.get();  // skip nl
                p2.m = p1.m;
                cmdDrawRect((char*)image, s, p1, p2, c);
                break;

            case DRAWH:
                std::cin >> p1.m >> p2.m >> p1.n >> c;
                std::cin.get();  // skip nl
                p2.n = p1.n;
                cmdDrawRect((char*)image, s, p1, p2, c);
                break;

            case DRAWR:
                std::cin >> p1.m >> p1.n >> p2.m >> p2.n >> c;
                std::cin.get();  // skip nl
                cmdDrawRect((char*)image, s, p1, p2, c);
                break;

            case FILL:
                std::cin >> p1.m >> p1.n >> c;
                std::cin.get();  // skip nl
                old_c = image[(p1.n - 1) * s.m + (p1.m - 1)];
                if (old_c != c) cmdFill((char*)image, s, p1, old_c, c);
                break;

            case STORE:
                std::cin >> name;
                cmdStore((char*)image, s, name);
                break;

            case EXIT:
                run = false;
                break;
        }
    }
}
