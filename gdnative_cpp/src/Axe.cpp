#include <Axe.h>
#include <CollisionShape2D.hpp>
#include <ResourceLoader.hpp>
#include <AnimatedSprite.hpp>

using namespace godot;

Player* Axe::player;

void Axe::_register_methods(){

    register_method("_process", &Axe::_process);
    register_method("_on_timeout", &Axe::_on_timeout);
    register_method("_speedUp", &Axe::_speedUp);

    register_property("Speed", &Axe::speed, 0.0f);
    register_property("Speed_Increament", &Axe::speedIncreament, 0.0f);
    register_property("Extents", &Axe::extents, Vector2(0, 0));
    // register_property<Player, Ref<PackedScene>>("OnDeathParticles", &Player::bloodSplatter, nullptr); crashes my godot
}

Axe::Axe() : speed(2.0f), attacking(true), direction(Vector2(0,0))
{

}

Axe::~Axe(){
    //clean-up
}

void Axe::_init(){
    ResourceLoader* resourceLoader = ResourceLoader::get_singleton();
    bloodSplatter = resourceLoader->load("res://BloodSplatter.tscn");
}

void Axe::_process(float delta){
    if(attacking){

        //Move and slide doesn't work
        Ref<KinematicCollision2D> collision = move_and_collide(direction * speed);
        if(collision != nullptr){
            attack();
        }
        checkOutOfBounce();
    }
    
}

void Axe::_on_timeout(){

    if(attacking){
    //Set direction to player
    direction = (player->get_position() - get_position()).normalized();
    float distanceToMouse = get_global_position().distance_to(player->get_position());

    //Normalize not working right so i'm doing it times distance to get an consistent speed
    direction *= distanceToMouse;
    }
}

void Axe::attack(){
    attacking = false;
    Godot::print("HIT");
    Node* blood = bloodSplatter->instance();
    static_cast<AnimatedSprite*>(blood)->_set_playing(true);
    add_child(blood);
    player->die();

    // static_cast<Timer*>(get_node("../Timer"))->disconnect("timeout", this, "_on_timeout"); didn't work and i don't know why
}

void Axe::checkOutOfBounce(){

    if (get_position().x + extents.x > get_viewport_rect().size.x || 
    get_position().y + extents.y > get_viewport_rect().size.y || 
    get_position().x - extents.x < 0 || 
    get_position().y - extents.y < 0) {
        direction *= 0;
	}
}

void Axe::_speedUp(){
    Godot::print("Sped up");
    speed += speedIncreament;
}
