#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec4 ourColor;
out vec4 ourPosition;
out vec2 TexCoord;
uniform float offset;

void main()
{
   ourPosition = vec4(aPos.x + offset, aPos.y, aPos.z, 1.0);
   gl_Position = ourPosition;
   ourColor = vec4(aColor, 1.0f);
   TexCoord = aTexCoord;
}