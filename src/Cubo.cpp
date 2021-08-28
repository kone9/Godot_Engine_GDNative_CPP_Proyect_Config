// Godot estructura del archivo Cpp
#include "Cubo.h"//incluir el archivo

//usar siempre el namespace
using namespace godot;

Cubo::Cubo() //CUIDADO PUEDE QUE EN LA API DE GODOT NO FUNCIONE TAN ASI// Un constructor se invoca cuando se crea un objeto de la clase mediante el operador new. Si es necesario invocarlo en otras situaciones, la llamada a un constructor solo puede realizarse desde dentro de otro constructor de su misma clase y debe ser siempre la primera instrucción.
{
    
}

Cubo::~Cubo() 
{
    
}


void Cubo::_init() //El metodo init no es el metodo _ready, siempre tiene que estar en todas las clases, no es necesario registrarlo, este siempre tiene que estar declarado en todas las clases
{
    
}

void Cubo::_ready() //se inicia cuando carga todo el juego
{
    
}


void Cubo::_process(real_t delta) 
{
    rotate( Vector3(0,1,0), (real_t)velocidadDeRotacion * delta);
}




void Cubo::_register_methods() //importante tenemos que registrar los metodos sino godot no los detecta, a veces al registrar las propiedades para que se vean en el editor no se cargan, si pasa eso, reinicia el editor
{
    register_method("_ready",&Cubo::_ready);//registro el _ready sino no funcion.
    register_method("_process",&Cubo::_process);//registro el _process sino no funcion.
    register_property("velocidadDeRotacion",&Cubo::velocidadDeRotacion, (float)1); 
}



