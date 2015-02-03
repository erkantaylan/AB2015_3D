#version 330
layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;

uniform float time;
uniform vec3 offset;

smooth out vec4 colorOut;

uniform float zNear;
uniform float zFar;

void main(){
	colorOut = color;
	vec4 totalOffset = vec4(offset.x, offset.y, offset.z, 0.0f);
	vec4 result = position + totalOffset;

	/*vec4 offset = vec4(cos(time*4)/4, sin(time/16)/4, 0.0f, 0.0f);*/

	result.x = -1 * result.x / result.z;
	result.y = -1 * result.y / result.z;
	result.z =  (result.z * (zNear + zFar) / (zNear - zFar)) + 2 * zNear * zFar / (zNear - zFar);
	gl_Position = result;
	colorOut = color;

	/*colorOut - offset;*/
}