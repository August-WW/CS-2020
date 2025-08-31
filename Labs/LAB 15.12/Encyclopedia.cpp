#include "Encyclopedia.h"
#include <iostream>

void Encyclopedia::SetEdition(string edition) {
    this->edition = edition;
}

void Encyclopedia::SetNumPages(int pages) {
    this->numPages = pages;
}

string Encyclopedia::GetEdition() const {
    return edition;
}

int Encyclopedia::GetNumPages() const {
    return numPages;
}

void Encyclopedia::PrintInfo() {
    Book::PrintInfo();
    cout << "   Edition: " << edition << endl;
    cout << "   Number of Pages: " << numPages << endl;
}
