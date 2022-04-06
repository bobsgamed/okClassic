//HDRTV GLSL shader
//license: GPL
//original version by SimoneT
//ruby port by byuu

uniform sampler2D Tex0;

void main(void) {
  vec4 rgb = texture2D(Tex0, gl_TexCoord[0].xy);
  vec4 intens = smoothstep(0.2,0.8,rgb) + normalize(vec4(rgb.xyz, 1.0));

  if(fract(gl_FragCoord.y * 0.5) > 0.5) intens = rgb * 0.8;
  gl_FragColor = intens;
}
