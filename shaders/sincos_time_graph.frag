#ifdef GL_ES
precision mediump float;
#endif

#define PI 3.14159265359

uniform vec2 u_resolution;
uniform vec2 u_mouse;
uniform float u_time;

float plot(vec2 st, float pct){
  return  smoothstep( pct-0.02, pct, st.y) -
          smoothstep( pct, pct+0.02, st.y);
}

void main() {
    vec2 st = gl_FragCoord.xy/u_resolution;

    //float y = smoothstep(abs(cos(u_time)),abs(sin(u_time)),st.x);
	//float y = smoothstep(0.2,0.5,st.x) - smoothstep(0.5,0.8,st.x);
    float y = (sin((gl_FragCoord.x/u_resolution.x+u_time)*5.5))/2.0+0.5;
    float x = (cos((gl_FragCoord.x/u_resolution.x+u_time/1.5)*5.5))/2.0+0.5;
    
    vec3 color = vec3((x+y)/2.0);

    float pct = plot(st,y);
    float pct2 = plot(st, x);
    color = (1.0-pct)*color+pct*vec3(0.0,1.0,0.0) + (-pct2)*color+pct2*vec3(0.0,1.0,0.0);

    
    gl_FragColor = vec4(color,1.0);
}