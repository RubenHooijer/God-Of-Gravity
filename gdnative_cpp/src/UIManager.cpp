#include "UIManager.h"
#include <Input.hpp>

using namespace godot;

void UIManager::_register_methods() {
    register_method("changescene", &UIManager::changescene);

    register_property<UIManager, String>("ScenePath", &UIManager::scenePath, "path");
}

UIManager::UIManager() : secondsPassed(0)
{
}

UIManager::~UIManager() {
    // add your cleanup here
}

void UIManager::_init() {

}

void UIManager::changescene(){
    SceneTree* tree = get_tree();
    tree->change_scene(scenePath);

    Input* input = Input::get_singleton();
    input->set_mouse_mode(Input::MouseMode::MOUSE_MODE_VISIBLE);
}

