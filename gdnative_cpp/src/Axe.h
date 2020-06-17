#ifndef AXE_H
#define AXE_H

#include <Godot.hpp>
#include <KinematicBody2D.hpp>
#include <KinematicCollision2D.hpp>
#include <Timer.hpp>
#include <Rect2.hpp>
#include <Player.h>
#include <PackedScene.hpp>

namespace godot {

    class Player;
    class Axe: public KinematicBody2D {

        GODOT_CLASS(Axe, KinematicBody2D)

    private : 
        bool attacking;
        float speed;
        float speedIncreament;
        Vector2 direction;

        Rect2 viewPort;
        Vector2 extents;

        Ref<PackedScene> bloodSplatter;
        
    public : static void _register_methods();

        static Player* player;

        Axe();
        ~ Axe();

        void _init();
        void _process(float delta);

        void _on_timeout();
        void _speedUp();

        void checkOutOfBounce();
        void attack();
    };
}

#endif // AXE_H
