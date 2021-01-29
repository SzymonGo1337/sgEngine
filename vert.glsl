#version 440

layout(location = 0) in vec3 a_Pos;
layout(location = 1) in vec2 a_TexCoord;

out vec2 v_TexCoord;

uniform mat4 u_ViewProjection = mat4(1.0);
uniform mat4 u_Transform = mat4(1.0);

void main() {
	v_TexCoord = a_Pos.xy;
	gl_Position = u_ViewProjection * u_Transform * vec4(a_Pos, 1.0);
}