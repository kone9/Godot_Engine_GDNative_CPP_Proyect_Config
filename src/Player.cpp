#include "Player.h"

using namespace godot;



Player::Player() //CUIDADO PUEDE QUE EN LA API DE GODOT NO FUNCIONE TAN ASI// Un constructor se invoca cuando se crea un objeto de la clase mediante el operador new. Si es necesario invocarlo en otras situaciones, la llamada a un constructor solo puede realizarse desde dentro de otro constructor de su misma clase y debe ser siempre la primera instrucción.
{
	
}

Player::~Player() //METODO DESTRUCTOR
{

}

void Player::_init() //El metodo init no es el metodo _ready, siempre tiene que estar en todas las clases, no es necesario registrarlo, este siempre tiene que estar declarado en todas las clases
{
	Godot::print("metodo _init cuando se carga el juego");
}

void Player::_ready() //se inicia cuando carga todo el juego
{
	Godot::print("metodo _ready cuando se cargan los nodos en la escena");
	motion = Vector2(0, 0);
}

void Player::_process(real_t delta) 
{
	// Godot::print(String::num_real(delta) );
	// Godot::print("Hola desde el bucle");
}

void Player::_physics_process(real_t delta) 
{
	move_and_slide(motion);
}

void Player::_input(godot::Ref<godot::InputEvent> event) 
{
	
	motion = Vector2(0, 0);

	Input* input = Input::get_singleton();//el input se obtiene por singleton.
	if(input == nullptr) return;//siempre hay que verificar los punteros

	if (input->is_action_pressed("w")) 
		motion.y -= movimiento * velocidadMovimiento;
	if (input->is_action_pressed("s")) 
		motion.y += movimiento * velocidadMovimiento;
	if (input->is_action_pressed("a")) 
		motion.x -= movimiento * velocidadMovimiento;
	if (input->is_action_pressed("d")) 
		motion.x += movimiento * velocidadMovimiento;
}


void Player::_register_methods()//importante tenemos que registrar los metodos sino godot no los detecta, a veces al registrar las propiedades para que se vean en el editor no se cargan, si pasa eso, reinicia el editor
{
	register_method("_ready",&Player::_ready);//fijate que declaro el metodo sin parametros ni nada, asi godot sabe que es el _ready
	register_method("_process", &Player::_process);//fijate que declaro el metodo sin parametros ni nada, asi godot sabe que es el _process
	register_method("_physics_process", &Player::_physics_process);//fijate que declaro el metodo sin parametros ni nada, asi godot sabe que es el _physics_process
	register_method("_input",&Player::_input);//fijate que declaro el metodo sin parametros ni nada, asi godot sabe que es el _process _input
	register_property<Player,float>("velocidadMovimiento",&Player::velocidadMovimiento,10);//para hacer export var, el primer parametro es el nombre que se ve en el editor, el segundo la variable que uso como referencia y el tercero el valor inicial
}

