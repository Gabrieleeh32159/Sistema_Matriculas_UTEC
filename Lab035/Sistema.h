//
// Created by estan on 12/2/2021.
//

#ifndef LAB035_SISTEMA_H
#define LAB035_SISTEMA_H
#include "Universidad.h"


class Sistema {
private:
    Universidad* universidad;
    int seleccionarMenu();
    void matricularAlumnoPreGrado();
    void matricularAlumnoPostGrado();
    void emitirListadoMatricula();
    void expotarListadoMatriculaExcel();
public:
    // Constructor
    Sistema();
    // Acceso
    Universidad *getUniversidad() const;
    void setUniversidad(Universidad *universidad);
    // Comportamiento
    void ejecutar();
    // Destructor
    virtual ~Sistema();
};


#endif //LAB035_SISTEMA_H
