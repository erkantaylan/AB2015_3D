#version 330
layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;

uniform float time;
uniform vec3 offset;

smooth out vec4 colorOut;

uniform mat4 perspectiveMat;
uniform mat4 translateMat;

void main() {
	vec4 result = translateMat   * position;
	gl_Position = perspectiveMat * result;
	colorOut = color;
}