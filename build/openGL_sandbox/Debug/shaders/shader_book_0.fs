#version 300 es
precision mediump float;
in vec4 TexColor;
out vec4 FragColor;

void main()
{
   FragColor = TexColor;
}