// Author:
// Title:

#ifdef GL_ES
precision mediump float;
#endif

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

vec3 makeRect(float x1, float y1, float x2, float y2)
{
    vec2 st = gl_FragCoord.xy/u_resolution.xy;
    return vec3(step(x1,st.x) * step(y1,st.y) * step(st.x, x2) * step(st.y, y2));
}

void main(){
    /*vec2 st = gl_FragCoord.xy/u_resolution.xy;
    vec3 color = vec3(0.0);
    float left = step(0.1,st.x);
    float bottom = step(0.1,st.y);
	float right = step(st.x,0.9);
    float top = step(st.y,0.9);
    
    color = vec3( left * bottom * right * top);*/
    vec3 color = vec3(0.0);
    
	color = makeRect(0.1, 0.2, 0.75, 0.75);
    gl_FragColor = vec4(color,1.0);
}