#include <assert.h>
#include <iostream>

enum class Size {
    XS,
    S,
    M,
    L,
    XL,
    Invalid
};

Size size(int cms) {
    Size sizeName = Size::Invalid;

    switch( cms){
        case 36:
            sizeName = Size::XS;
            break;
        case 38:
            sizeName =  Size::S;
            break;
        case 40:
            sizeName = Size::M;
            break;
        case 42:
            sizeName = Size::L;
            break;
        case 44:
            sizeName = Size::XL;
            break;
    }
    return sizeName;
}

void testSize(){
    assert(size(36) == Size::XS);
    assert(size(38) == Size::S);
    assert(size(40) == Size::M);
    assert(size(42) == Size::L);
    assert(size(44) == Size::XL);
    assert(size(37) == Size::Invalid);
    assert(size(39) == Size::Invalid);
    assert(size(41) == Size::Invalid);
    assert(size(43) == Size::Invalid);
    std::cout << "All is well (maybe!)\n";
}

int main() {
    testSize();
    return 0;
}
