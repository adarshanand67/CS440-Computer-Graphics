#version 430 core

layout(location=0) in vec4 inputSetCoords;

void main(void)
{
   gl_Position = inputSetCoords;
}
