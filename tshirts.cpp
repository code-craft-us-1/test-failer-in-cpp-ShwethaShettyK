#include <assert.h>
#include <iostream>

char size(int cms) {
    char sizeName = '\0';
    if (cms < 38) {
        sizeName = 'S';
    } else if (cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if (cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

int main() {
    assert(size(36) == 'XS');
    assert(size(38) == 'S');
    assert(size(40) == 'M');
    assert(size(42) == 'L');
    assert(size(37) == '\0');
    assert(size(39) == '\0');
    asssert(size(41) == '\0');
    assert(size(43) == '\0');
    std::cout << "All is well (maybe!)\n";
    return 0;
}
