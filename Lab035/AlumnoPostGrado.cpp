//
// Created by estan on 12/2/2021.
//

#include "AlumnoPostGrado.h"

AlumnoPostGrado::AlumnoPostGrado(const string &codigo, const string &nombre, const string &apellidoPaterno,
                                 const string &apellidoMaterno, const string &empresaTrabajo) : Alumno(codigo, nombre,
                                                                                                       apellidoPaterno,
                                                                                                       apellidoMaterno),
                                                                                                empresaTrabajo(
                                                                                                        empresaTrabajo) {}

const string &AlumnoPostGrado::getEmpresaTrabajo() const {
    return empresaTrabajo;
}

void AlumnoPostGrado::setEmpresaTrabajo(const string &empresaTrabajo) {
    AlumnoPostGrado::empresaTrabajo = empresaTrabajo;
}

void AlumnoPostGrado::mostrar() {
    Alumno::mostrar();
    cout << empresaTrabajo<<endl;
}

string AlumnoPostGrado::serializar() {
    // Invocar al metodos del ancetro
    // Formato:
    // NombreClase::Metodo
    return Alumno::serializar() + "|" + empresaTrabajo + "|";
}

AlumnoPostGrado::~AlumnoPostGrado() {
    empresaTrabajo="";
}

string AlumnoPostGrado::csv() {
    return Alumno::csv()+ ",PostGrado,"+empresaTrabajo;
}

