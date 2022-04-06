//
// Created by estan on 12/2/2021.
//

#include "Sistema.h"
#include <string>


Sistema::Sistema() {
    universidad = new Universidad("UTEC.dat" );
}

Universidad *Sistema::getUniversidad() const {
    return universidad;
}

void Sistema::setUniversidad(Universidad *universidad) {
    Sistema::universidad = universidad;
}

void Sistema::ejecutar() {
    int opcion = 0;
    do{
        opcion = seleccionarMenu();
        switch (opcion) {
            case 1:
                matricularAlumnoPreGrado();
                break;
            case 2:
                matricularAlumnoPostGrado();
                break;
            case 3:
                emitirListadoMatricula();
                break;
            case 4:
                expotarListadoMatriculaExcel();
                break;
        }
    } while (opcion != 5);
}

int Sistema::seleccionarMenu() {
    int opcion=0;
    cout << "UTEC - Sistema de Matricula de Alumnos\n"<<endl;
    cout << "[1] Matricular Alumnos de Pre-Grado"<<endl;
    cout << "[2] Matricular Alumnos de Post-Grado"<<endl;
    cout << "[3] Reporte de Alumnos Matriculados"<<endl;
    cout << "[4] Exportar Matricula a Excel"<<endl;
    cout << "[5] Salir"<<endl;
    cout << "Opcion: "; cin>>opcion;
    return opcion;
}

void Sistema::matricularAlumnoPreGrado() {
    cin.ignore();
    string codigo, nombre, apellidoPaterno, apellidoMaterno, apoderado;
    cout<<"Matricula de Alumno a Pre-Grado\n"<<endl;
    cout << "Codigo: "; getline(cin, codigo);
    if (universidad->buscarAlumno(codigo) == nullptr){
        cout << "Nombre: "; getline(cin,nombre);
        cout << "Apellido Paterno: "; getline(cin,apellidoPaterno);
        cout << "Apellido Materno: "; getline(cin, apellidoMaterno);
        cout << "Apoderado: "; getline(cin,apoderado);
        universidad->matricularAlumnoPreGrado(codigo, nombre, apellidoPaterno, apellidoMaterno, apoderado);
    } else{
        cout << "Codigo de alumno duplicado. Revisar."<<endl;
    }

}

void Sistema::matricularAlumnoPostGrado() {
    cin.ignore();
    string codigo, nombre, apellidoPaterno, apellidoMaterno, empresa;
    cout<<"Matricula de Alumno a Post-Grado\n"<<endl;
    cout << "Codigo: "; getline(cin, codigo);
    if (universidad->buscarAlumno(codigo) == nullptr){
        cout << "Nombre: "; getline(cin,nombre);
        cout << "Apellido Paterno: "; getline(cin,apellidoPaterno);
        cout << "Apellido Materno: "; getline(cin, apellidoMaterno);
        cout << "Empresa donde labora: "; getline(cin,empresa);
        universidad->matricularAlumnoPostGrado(codigo, nombre, apellidoPaterno, apellidoMaterno, empresa);
    }else {
        cout << "Codigo de alumno duplicado. Revisar."<<endl;
    }

}

void Sistema::emitirListadoMatricula() {
    universidad->emitirListadoAlumnosMatriculados();
}

void Sistema::expotarListadoMatriculaExcel() {
    cin.ignore();
    cout << "Exportar Matricula a Excel\n"<<endl;
    string archivoExcel="";
    cout << "Nombre archivo: ";
    getline(cin, archivoExcel);
    universidad->exportarListadoMatriculaExcel(archivoExcel);

}


Sistema::~Sistema() {
    delete universidad;
}

