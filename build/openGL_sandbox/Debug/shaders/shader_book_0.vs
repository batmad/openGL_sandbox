#version 300 es
layout (location = 0) in vec4 aPos;
layout (location = 1) in vec4 aTexColor;

uniform float u_offset;
out vec4 TexColor;

void main()
{
   TexColor = aTexColor;
   gl_Position = aPos;
   gl_Position.x += u_offset;
}