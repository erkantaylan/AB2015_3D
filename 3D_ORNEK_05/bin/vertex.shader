#version 330
layout(location = 0) in vec4 position;
uniform float time;

void main(){
	vec4 offset = vec4(cos(time*4)/4, sin(time/16)/4, 0.0f, 0.0f);
	gl_Position = position + offset;
}