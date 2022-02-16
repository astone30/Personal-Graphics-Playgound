#ifndef RENDERABLE_H
#define RENDERABLE_H

#ifndef MATH_H
#include "math.hpp"
#endif

using namespace mathmetic;

typedef unsigned int GLenum;
struct Shader
{
    unsigned int id;
    Shader(const char* vertPath, const char* fragPath);
    private:
    void Init(const char* path, GLenum glenum, unsigned int& shader_id);
};

class Shape
{
    private:
    unsigned int vao, vbo, ebo, cbo;
    unsigned int outline_ebo;
    int vert, indicies, outline_ind = 0;

    
    int SetBuffer(unsigned int& id, unsigned int buffer, const std::vector<fvec3>& data, unsigned int useage, unsigned int type, int index, int point);
    int SetBuffer(unsigned int& id, unsigned int buffer, const std::vector<ivec3>& data, unsigned int useage);
    
    public:
    Shape();
    Shape(const std::vector<fvec3>& _vert);
    Shape(const std::vector<fvec3>& _vert, const std::vector<ivec3>& _indicies);
    Shape(const std::vector<fvec3>& _vert, const std::vector<fvec3>& _color);
    Shape(const std::vector<fvec3>& _vert, const std::vector<fvec3>& _color, const std::vector<ivec3>& _indicies);

    void SetOutLine(const std::vector<ivec2>& _indicies);

    void Draw();
};


#endif