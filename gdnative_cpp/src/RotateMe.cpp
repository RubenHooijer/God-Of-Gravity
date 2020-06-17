#include <RotateMe.h>

using namespace godot;

void RotateMe::_register_methods(){

    register_method("_process", &RotateMe::_process);

    register_property("Rotate_Speed", &RotateMe::rotateSpeed, 0.0f);

}

RotateMe::RotateMe() : rotateSpeed(0.0f)
{

}

RotateMe::~RotateMe(){
    //clean-up
}

void RotateMe::_init(){

}

void RotateMe::_process(float delta){
    rotate();
    
}

void RotateMe::rotate(){
    Node2D::rotate(rotateSpeed);
}