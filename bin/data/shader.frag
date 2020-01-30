#version 400
in vec4 vPosition;
out vec4 outputColor;
uniform float u_textbox_height;
uniform vec4 globalColor;

void main(){
  float y = step(vPosition.y, 10) - step(vPosition.y, -1*u_textbox_height+10);
  outputColor = vec4(globalColor.rgb, y);
}
