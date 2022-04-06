//
// Created by estan on 12/2/2021.
//

#ifndef LAB035_ALUMNOPREGRADO_H
#define LAB035_ALUMNOPREGRADO_H
#include "Alumno.h"

// Establecer la relacion de herencia
class AlumnoPreGrado: public Alumno{
private:
    string apoderado;
public:
    // Constructor
    AlumnoPreGrado(const string &codigo, const string &nombre, const string &apellidoPaterno,
                   const string &apellidoMaterno, const string &apoderado);
    // Acceso
    const string &getApoderado() const;
    void setApoderado(const string &apoderado);
    // Comportamiento
    void mostrar() override;
    string serializar() override;

    string csv() override;

    // Destructor
    ~AlumnoPreGrado() override;

};


#endif //LAB035_ALUMNOPREGRADO_H
