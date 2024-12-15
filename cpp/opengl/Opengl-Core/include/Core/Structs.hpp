#pragma once

struct Color {
    float r = 0.f, g = 0.f, b = 0.f, a = 1.f;
};

struct RBConfig {
    unsigned int format = 0;
    unsigned int attachment = 0;
    unsigned int width = 0;
    unsigned int height = 0;
};

struct FBConfig {
    unsigned int operation = 0;
    unsigned int width = 0;
    unsigned int height = 0;
};
