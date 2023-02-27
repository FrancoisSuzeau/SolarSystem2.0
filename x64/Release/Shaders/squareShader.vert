// ============ GLSL version ============
#version 400 core

// ============ In data ============
in vec3 in_Vertex;
uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

// ============ Out data ============


void main()
{

    gl_Position = projection * view * (model * vec4(in_Vertex, 1.0));

}
