#include <iostream>
#include "Sistema.h"
int main() {
    Sistema* matricula = new Sistema();
    matricula->ejecutar();
    delete matricula;
    return 0;
}
