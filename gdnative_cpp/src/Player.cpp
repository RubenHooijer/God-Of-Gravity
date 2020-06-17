#include "Player.h"


using namespace godot;

void Player::_register_methods() {
    register_method("_process", &Player::_process);
    register_method("_ready", &Player::_ready);

    register_property("Extents", &Player::extents, Vector2(0,0));

    register_signal<Player>("_on_death", godot::Dictionary());
}

Player::Player() : extents(Vector2(0,0))
{
}

Player::~Player() {
    // add your cleanup here
}

void Player::_init() {
    Input* input = Input::get_singleton();
    input->set_mouse_mode(Input::MouseMode::MOUSE_MODE_HIDDEN);
}

void Player::_ready(){
    Axe::player = this;
}

void Player::_process(float delta){

    movement();

}

void Player::movement(){

    Vector2 newPos = get_global_mouse_position();

    //Checks if not out of bounce
    if (newPos.x + extents.x > get_viewport_rect().size.x)
    {
        newPos.x = get_viewport_rect().size.x - extents.x;
    } else if (newPos.x - extents.x < 0)
    {
        newPos.x = 0 + extents.x;
    }

    if (newPos.y + extents.y > get_viewport_rect().size.y)
    {
        newPos.y = get_viewport_rect().size.y - extents.y;
    } else if (newPos.y - extents.y < 0)
    {
        newPos.y = 0 + extents.y;
    }

    set_position(newPos);
}

void Player::die(){
    emit_signal("_on_death");
    set_visible(false);
}