//
// Created by estan on 12/2/2021.
//

#include "Universidad.h"
#include "AlumnoPreGrado.h"
#include "AlumnoPostGrado.h"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

Universidad::Universidad(string nombreArchivoDatos) {
    // Nombre del archivo en donde se realizará la serializacion de objetos
    this->nombreArchivoDatos = nombreArchivoDatos;
    // Instancias a la coleccion de alumnos (lo tenemos en composicion)
    alumnos=new vector<Alumno*>();
    // Desarializamos el archivo para recuperar a los objetos almacenados en el archivo de datos
    deserializar();
}

Alumno *Universidad::deserializarAlumno(string datosAlumno) {
    vector<string>* campos = new vector<string>();
    string s = datosAlumno;
    string delimiter = "|";
    size_t pos = 0;
    string token;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        campos->push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    string nombreClase = campos->at(0);
    string codigo = campos->at(1);
    string nombre = campos->at(2);
    string apellidoPaterno = campos->at(3);
    string apellidoMaterno = campos->at(4);
    string datoExtra = campos->at(5);
    delete campos;
    if (nombreClase=="class AlumnoPreGrado")
        return new AlumnoPreGrado(codigo, nombre, apellidoPaterno, apellidoMaterno, datoExtra);
    else
        return new AlumnoPostGrado(codigo, nombre, apellidoPaterno, apellidoMaterno, datoExtra);
}

void Universidad::deserializar() {
    // Usamos input file stream para hacer la lectura del archivo
    ifstream* file = new ifstream (nombreArchivoDatos);
    // Verificar si se pudo abrir el archivo para lectura
    if (file->is_open()){
        string datosAlumno;
        while (getline(*file, datosAlumno)){
            alumnos->push_back(deserializarAlumno(datosAlumno));
        }
        file->close();
        delete file;
    }else{
        cout << "No se puede abrir archivo de datos "<<nombreArchivoDatos<<endl;
    }
}


vector<Alumno *> *Universidad::getAlumnos() const {
    return alumnos;
}

void Universidad::setAlumnos(vector<Alumno *> *alumnos) {
    Universidad::alumnos = alumnos;
}

void Universidad::matricularAlumnoPreGrado(const string &codigo, const string &nombre, const string &apellidoPaterno,
                                           const string &apellidoMaterno, const string &apoderado) {
    alumnos->push_back(new AlumnoPreGrado(codigo, nombre, apellidoPaterno, apellidoMaterno, apoderado));
    ordenarAlfabeticamenteXApellidoPaterno();
}

void Universidad::matricularAlumnoPostGrado(const string &codigo, const string &nombre, const string &apellidoPaterno,
                                            const string &apellidoMaterno, const string &empresaTrabajo) {
    alumnos->push_back(new AlumnoPostGrado(codigo, nombre, apellidoPaterno, apellidoMaterno, empresaTrabajo));
    ordenarAlfabeticamenteXApellidoPaterno();
}

void Universidad::emitirListadoAlumnosMatriculados() {
    cout <<"Codigo\tApellidos y Nombre\tApoderado/Empresa"<<endl;
    for(const auto alumno : *alumnos)
        alumno->mostrar();
}

void Universidad::serializar() {
    // Grabar en cada linea de un archivo la
    // serialización de un objeto
    // Para hacer la escritura del archivo se usará Output File Stream
    // 1. Abrir el archivo para escritura
    ofstream* file = new ofstream (nombreArchivoDatos);
    // 2. Si se pudo abrir el archivo se procede a escribir linea a linea
    if (file->is_open()){
        for(const auto alumno: *alumnos)
            *file << alumno->serializar() << endl;
        file->close();
        delete file;
    }else{
        cout << "No se puede generar archivo "<<nombreArchivoDatos<<endl;
    }
}

void Universidad::exportarListadoMatriculaExcel(string nombreExcel) {
    nombreExcel=nombreExcel+".csv";
    ofstream* file = new ofstream (nombreExcel);
    *file <<"Codigo,Apellido Paterno,Apellido Materno,Nombre,Modalidad,Apoderado/Empresa"<<endl;
    if (file->is_open()){
        for(const auto alumno: *alumnos)
            *file << alumno->csv() << endl;
        file->close();
        delete file;
    }else{
        cout << "No se puede generar archivo "<<nombreExcel<<endl;
    }
}

Alumno *Universidad::buscarAlumno(string codigo) {
    auto alumno = find_if(alumnos->begin(), alumnos->end(), [codigo](Alumno* item){return codigo == item->getCodigo();});
    if (alumno != alumnos->end())
        return *alumno;
    return nullptr;
}

void Universidad::ordenarAlfabeticamenteXApellidoPaterno() {
    sort(alumnos->begin(), alumnos->end(), [](Alumno* a1, Alumno* a2){return a1->getApellidoPaterno() < a2->getApellidoPaterno(); });
}


Universidad::~Universidad() {
    // Antes de liberar a los objetos, almacenamos su serializacion
    serializar();
    // Liberar a los objetos
    for(const auto alumno : *alumnos)
        delete alumno;
    delete alumnos;
}






