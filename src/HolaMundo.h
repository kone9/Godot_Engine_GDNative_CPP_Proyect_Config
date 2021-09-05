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
           //Para hacer la magia de usar Godot Engine con C++ y Gdnative hay que registrar metodos y propiedades con este metodo... //IMPORTANTE tenemos que registrar los metodos sino godot no los detecta, a veces al registrar las propiedades para que se vean en el editor no se cargan, si pasa eso, reinicia el editor
            static void _register_methods();

            //Estos metodos heredan de Node, por lo tanto si quieres saber de donde
            //salen tienes que buscar la clase Node y ver como estan declarados y definidos
            //no son metodos abstractos como si lo son en C# o Gdscript
            //El metodo "_register_methods()" que declare aqui arriba se ecnarga de hacer 
            //la magia para que funcionen dentro de godot engine como si fueran 
            //los metodos convencionales de godot.

            //Osea para ver como se escriben tendrias que escribir:
            //godot::Node::_ready
            //godot::Node::_process
            //godot::Node::_physics_process;
            //Osea tene en cuenta que solo es para ver como se definen, luego
            //tenes que escribirlos aqui y registrarlos con _register_methods()
            //como esta hecho en la clase Cpp
            //Por ahora usan la API antigua de Godot Engine, tenelo en cuenta

            //metodo init no es el ready.PRECAUCION: si llamas a los nodos desde aca vas a tener punteros colgados y se va a cerrar la aplicacion. Se puede usar para definir cosas, pero en las practicas que yo hice no pude buscar nodos desde aca. "Es llamada una vez que Godot ha creado nuestro objeto adecuadamente"..Este método no se registra y es obligatorio que este en todas las clases 
            void _init();
            //metodo ready de godot, desde aca podes llamar a los nodos cuando se carganla escena, se ejecuta una sola vez.. Este metodo tiene que estar registrado
            void _ready();
        
	};
}

#endif