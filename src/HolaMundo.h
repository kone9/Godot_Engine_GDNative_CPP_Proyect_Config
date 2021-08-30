// Godot engine C++ Gdnative Estructura de un archivo
#ifndef HOLAMUNDO_H//nose si sea necesario, pero esto lo saque de los ejemplos lo dejo por las dudas, asi funciona
#define HOLAMUNDO_H//nose si sea necesario, pero esto lo saque de los ejemplos lo dejo por las dudas, asi funciona

#pragma once//importante siempre incluir esta linea

//importamos las librerias que necesitamos
#include <Godot.hpp>
#include <Node2D.hpp>

//siempre usamos el nameSpace para que sea identificada la clase por todo el proyecto
namespace godot {
	class HolaMundo : public Node2D {
        // Respetar que el macro tenga el acceso privado
        private:
            GODOT_CLASS(HolaMundo, Node2D)  

        public:
            //metodo contructor, ojo no se llama directo, usar init()
            HolaMundo();
            //metodo destructor, ni idea como funciona en godot, pero lo declaramos por las dudas aunque no lo usemos
            ~HolaMundo();

            void _ready();

           //Para hacer la magia de usar Godot Engine con C++ y Gdnative hay que registrar metodos y propiedades con este metodo... //IMPORTANTE tenemos que registrar los metodos sino godot no los detecta, a veces al registrar las propiedades para que se vean en el editor no se cargan, si pasa eso, reinicia el editor
            static void _register_methods();
        
	};
}

#endif