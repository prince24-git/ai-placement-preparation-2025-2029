#include <iostream>

void hanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        std::cout << "Move disk 1 from " << source << " to " << destination << '\n';
        return;
    }

    hanoi(n - 1, source, destination, auxiliary);
    std::cout << "Move disk " << n << " from " << source << " to " << destination << '\n';
    hanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int disks;

    std::cout << "Enter number of disks: ";
    if (!(std::cin >> disks) || disks <= 0) {
        std::cout << "Please enter a positive number of disks.\n";
        return 1;
    }

    hanoi(disks, 'A', 'B', 'C');
    return 0;
}
