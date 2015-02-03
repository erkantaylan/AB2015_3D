#version 330
uniform float time;

void main() {
	gl_FragColor = vec4(
		(sin(time * 4.0f) + 1.0f) / 2.0f
		, (cos(time * 4.0f) + 2.0f) / 2.0f
		, (tan(time * 4.0f) + 1.0f) / 2.0f
		, 1.0f);
	/*4 kat daha hizli degis ve -1 ile 1 arasinda degilde
	 0 ile 2 arasinda degis,
	 sonra 2 ye bol ki 0 ile 1 arasinda degissin*/
}