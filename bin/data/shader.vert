#version 400

layout(location = 0) in vec4 position;
uniform mat4 modelViewProjectionMatrix;
uniform float u_animation;

out vec4 vPosition;

void main(){
  vec4 p = position;
  p.y += u_animation;
  vPosition = p;
  gl_Position = modelViewProjectionMatrix * p;
}
