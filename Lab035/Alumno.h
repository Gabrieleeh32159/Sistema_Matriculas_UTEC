//
// Created by estan on 12/2/2021.
//

#ifndef LAB035_ALUMNO_H
#define LAB035_ALUMNO_H
#include <iostream>
using namespace std;

// Clase Abstracta
class Alumno {
protected:
    string codigo;
    string nombre;
    string apellidoPaterno;
    string apellidoMaterno;
public:
    // Constructor
    Alumno(const string &codigo, const string &nombre, const string &apellidoPaterno, const string &apellidoMaterno);
    // Acceso
    const string &getCodigo() const;
    void setCodigo(const string &codigo);
    const string &getNombre() const;
    void setNombre(const string &nombre);
    const string &getApellidoPaterno() const;
    void setApellidoPaterno(const string &apellidoPaterno);
    const string &getApellidoMaterno() const;
    void setApellidoMaterno(const string &apellidoMaterno);
    // Comportamiento
    virtual void mostrar();
    virtual string serializar();
    virtual string csv();
    // Destructor
    virtual ~Alumno();
};


#endif //LAB035_ALUMNO_H
