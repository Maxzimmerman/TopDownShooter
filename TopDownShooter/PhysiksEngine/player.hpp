#pragma once
#include <iostream>
#include <raylib.h>
#include <raymath.h>

class Player {
    private:
        Vector2 position;
        int width;
        int height;
        float gravity;
    public:
        Player();
        Player(Vector2 pos);
        Player(Vector2 pos, float gravity);
        void Update();
        void Draw();
};