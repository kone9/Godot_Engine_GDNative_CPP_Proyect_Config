//EJEMPLO de archivo para registrar las clases.
//este archivo no posee .h, es solo el .cpp
//ACA REGISTRAREMOS TODAS LAS CLASES QUE CREAMOS

#include "Player.h"//importante siempre importar la clase para registrarla
#include "Cubo.h"//importante siempre importar la clase para registrarla

using namespace godot;//usamos el espacio de nombres godot sino tenemos varios problemas, no podra explicar mucho esto, pero asi funciona

///////////////////////////////////////////////////
// Las funciones godot_gdnative_init y godot_gdnative_terminate son llamadas
// respectivamente cuando Godot carga nuestro plugin y cuando lo descarga.
// Todo lo que que hacemos aquí es analizar a través de estas funciones
// en nuestro módulo de enlaces para inicializarlo, pero podrías tener que configurar
// más cosas dependiendo de tus necesidades. Por ahora lo dejamos asi sin tocarlo.

extern "C" void GDN_EXPORT godot_gdnative_init(godot_gdnative_init_options * o) {
	Godot::gdnative_init(o);
}

extern "C" void GDN_EXPORT godot_gdnative_terminate(godot_gdnative_terminate_options * o) {
	Godot::gdnative_terminate(o);
}

//////////////////////////////////////////////////

//-> ESTE ES EL MAS IMPORTANTE METODO PARA REGISTRAR CLASES <- //
extern "C" void GDN_EXPORT godot_nativescript_init(void* handle)
{
	Godot::nativescript_init(handle);//Precaución no borrar esto.
	
	//Registramos todas las clases que creamos aqui abajo
	register_class<Player>();//registre la clase player
	register_class<godot::Cubo>();//registre la clase Cubo
	//register_class<YOUCLASE>();//registra tu clase!
	
}