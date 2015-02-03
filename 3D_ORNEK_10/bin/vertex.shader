#version 330
layout(location = 0) in vec4 position;
uniform float time;
uniform vec3 offset;
smooth out vec4 colorOut;
layout(location = 1) in vec4 color;


void main(){
	colorOut = color;
	vec4 totalOffset = vec4(offset.x, offset.y, offset.z, 0.0f);
	/*vec4 offset = vec4(cos(time*4)/4, sin(time/16)/4, 0.0f, 0.0f);*/
	gl_Position = position + totalOffset;
}