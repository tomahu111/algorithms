// Author:
// Title:

#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform float u_time;

vec3 colorA = vec3(0.149,0.141,0.912);
vec3 colorB = vec3(1.000,0.533,0.024);
#define PI 3.14
void main() {
    vec3 color = vec3(0.0);
	//colorB.g=abs(cos(u_time));
    //float x=tan(u_time);
    float x = gl_FragCoord.x/u_resolution.x;
    float c1=1.70158;
    float c3=c1+abs(sin(u_time));
    float curve=abs(sin(u_time+gl_FragCoord.y/u_resolution.y)+1.0)*2.0;
    //colorA.b=x*x*x*2.70158+x*x+1.70158;
    c3=c3+curve/2.0;
    float pct = abs(sin(u_time));
	pct=1.0 + c3 * pow(x - 1.0, 3.0) + c1 * pow(x - 1.0, 2.0);
    // Mix uses pct (a value from 0-1) to
    // mix the two colors
    color = mix(colorA, colorB, pct);
//return 1 + c3 * pow(x - 1, 3) + c1 * pow(x - 1, 2);
//return c3 * x * x * x - c1 * x * x;
    gl_FragColor = vec4(color,1.0);
}