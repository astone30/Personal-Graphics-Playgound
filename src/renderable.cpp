#include "renderable.hpp"

#include <stdio.h>
#include <cstring>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


// Define Shader
Shader::Shader(const char* vertPath, const char* fragPath)
{
    unsigned int vert_shader, frag_shader;
    
    Init(vertPath, GL_VERTEX_SHADER,  vert_shader);
    Init(fragPath, GL_FRAGMENT_SHADER, frag_shader);

    id = glCreateProgram();
    glAttachShader(id, vert_shader);
    glAttachShader(id, frag_shader);
    glLinkProgram(id);

    glDeleteShader(vert_shader);
    glDeleteShader(frag_shader);
}

void Shader::Init(const char* path, GLenum glenum, unsigned int& shader_id)
{
    unsigned int file_size, count; 
    FILE* shader_file = fopen(path, "r");
    fseek(shader_file, 0, SEEK_END);
    file_size = ftell(shader_file);
    char* shader_code = new char[file_size+1];
    memset(shader_code, 0, file_size);
    fseek(shader_file, 0, SEEK_SET);
    count = fread(shader_code, file_size, 1, shader_file);
    shader_id = glCreateShader(glenum);
    glShaderSource(shader_id, 1, &shader_code, NULL);
    glCompileShader(shader_id);
    
    int success;
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char infoLog[512];
        glGetShaderInfoLog(shader_id, 512, NULL, infoLog);
        printf(infoLog);
    }
    
    fclose(shader_file);
    delete(shader_code);
}

// Shader end

// Define Shape
Shape::Shape()
{
    vert     = 0;
    indicies = 0;
}

Shape::Shape(const std::vector<fvec3>& _vert) : Shape()
{
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    vert = SetBuffer(vbo, GL_ARRAY_BUFFER, _vert, GL_STATIC_DRAW, GL_FLOAT, 0, 0);
    
    glBindVertexArray(0);
}

Shape::Shape(const std::vector<fvec3>& _vert, const std::vector<ivec3>& _indicies) : Shape()
{
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    vert = SetBuffer(vbo, GL_ARRAY_BUFFER, _vert, GL_STATIC_DRAW, GL_FLOAT, 0, 0);
    indicies = SetBuffer(ebo, GL_ELEMENT_ARRAY_BUFFER, _indicies, GL_STATIC_DRAW);

    glBindVertexArray(0);
}

Shape::Shape(const std::vector<fvec3>& _vert, const std::vector<fvec3>& _color) : Shape()
{
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    
    vert = SetBuffer(vbo, GL_ARRAY_BUFFER, _vert, GL_STATIC_DRAW, GL_FLOAT, 0, 0);
    SetBuffer(cbo, GL_ARRAY_BUFFER, _color, GL_STATIC_DRAW, GL_FLOAT, 1, 1);
    
    glBindVertexArray(0);
}

Shape::Shape(const std::vector<fvec3>& _vert, const std::vector<fvec3>& _color, const std::vector<ivec3>& _indicies) : Shape()
{
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    vert = SetBuffer(vbo, GL_ARRAY_BUFFER, _vert, GL_STATIC_DRAW, GL_FLOAT, 0, 0);
    SetBuffer(cbo, GL_ARRAY_BUFFER, _color, GL_STATIC_DRAW, GL_FLOAT, 1, 1);
    indicies =  SetBuffer(ebo, GL_ELEMENT_ARRAY_BUFFER, _indicies, GL_STATIC_DRAW);

    glBindVertexArray(0);

}


int Shape::SetBuffer(unsigned int& id, unsigned int buffer, const std::vector<fvec3>& data, unsigned int useage, unsigned int type, int index, int point)
{
    glGenBuffers(1, &id);
    glBindBuffer(buffer, id);
    glBufferData(buffer, data.size() * sizeof(fvec3), &data[0], useage);

    glVertexAttribPointer(point, 3, type, GL_FALSE, sizeof(fvec3), (void *)0);
    glEnableVertexAttribArray(index);

    glBindBuffer(buffer, 0);
    return data.size();
}

int Shape::SetBuffer(unsigned int& id, unsigned int buffer, const std::vector<ivec3>& data, unsigned int useage)
{
    glGenBuffers(1, &id);
    glBindBuffer(buffer, id);
    glBufferData(buffer, data.size() * sizeof(ivec3), &data[0], useage);

    glBindBuffer(buffer, 0);
    return data.size();
}

void Shape::SetOutLine(const std::vector<ivec2>& _indicies)
{
    glBindVertexArray(vao);
    outline_ind = _indicies.size();
    glGenBuffers(1, &outline_ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, outline_ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indicies.size() * sizeof(ivec2), &_indicies[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

//(GLenum mode, GLsizei count, GLenum type, const void *indices);
void Shape::Draw()
{
    glBindVertexArray(vao);
    
    if(indicies != 0)
    {
        //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        //glDrawElements(GL_TRIANGLES, indicies * 3, GL_UNSIGNED_INT, 0);
        //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
    else
    {
        glDrawArrays(GL_TRIANGLES, 0, vert);
    }

    if(outline_ind != 0)
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, outline_ebo);
        glLineWidth(5.0f);
        glDrawElements(GL_LINES, outline_ind * 2, GL_UNSIGNED_INT, 0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
    glBindVertexArray(0);
}

// Shape end
