#include "HolaMundo.h"

using namespace godot;

HolaMundo::HolaMundo() 
{
    
}

HolaMundo::~HolaMundo() 
{
    
}

void HolaMundo::_init() 
{
    
}


void HolaMundo::_ready()
{
    Godot::print("Hola Mundo C++ GDnative");
}


void HolaMundo::_register_methods() 
{
    register_method("_ready",&HolaMundo::_ready);//registro a ready
}





