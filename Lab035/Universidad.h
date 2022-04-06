//
// Created by estan on 12/2/2021.
//

#ifndef LAB035_UNIVERSIDAD_H
#define LAB035_UNIVERSIDAD_H

#include "Alumno.h"
#include <vector>
class Universidad {
private:
    string nombreArchivoDatos;
    vector<Alumno*>* alumnos;
    void serializar();
    void deserializar();
    Alumno* deserializarAlumno(string datosAlumno);
    void ordenarAlfabeticamenteXApellidoPaterno();
public:
    // Constructor
    Universidad(string nombreArchivoDatos);
    // Acceso
    vector<Alumno *> *getAlumnos() const;
    void setAlumnos(vector<Alumno *> *alumnos);
    // Comportamiento
    void matricularAlumnoPreGrado(const string &codigo, const string &nombre, const string &apellidoPaterno,
                                  const string &apellidoMaterno, const string &apoderado);
    void matricularAlumnoPostGrado(const string &codigo, const string &nombre, const string &apellidoPaterno,
                                   const string &apellidoMaterno, const string &empresaTrabajo);
    void emitirListadoAlumnosMatriculados();
    void exportarListadoMatriculaExcel(string nombreExcel);
    Alumno* buscarAlumno(string codigo);
    // Destructor
    virtual ~Universidad();
};


#endif //LAB035_UNIVERSIDAD_H
