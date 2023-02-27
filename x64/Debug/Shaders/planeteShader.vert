// ============ GLSL version ============
#version 400 core

// ============ In data ============
in vec3 in_Vertex;
in vec2 in_TexCoord0;
uniform mat4 view;
uniform mat4 model;
uniform mat4 projection;
uniform vec3 viewPos;
uniform vec3 sunPos;

// ============ Out data ============
out VS_OUT {
    vec3 Normal;
    vec3 FragPos;
    vec4 texCoords;
    vec3 TangentLightPos;
    vec3 TangentViewPos;
    vec3 TangentFragPos;
} vs_out;


void main(void) {

    vs_out.FragPos = vec3(model * vec4(in_Vertex, 1.0));
    mat3 normalMatrice = mat3(transpose(inverse(model)));
    vs_out.Normal = normalize(normalMatrice * in_Vertex);  
    vs_out.texCoords = vec4(in_Vertex, 1.0);
    gl_Position = projection * view * (model * vec4(in_Vertex, 1.0));

    vec3 lightPos = sunPos;

    vec3 v = vec3(vs_out.Normal.x + 1, vs_out.Normal.y, vs_out.Normal.z);
    vec3 k = vs_out.Normal * v;
    vec3 Tangent = v - k * vs_out.Normal;

    vec3 T = normalize(vec3(model * vec4(Tangent, 0.0)));
    vec3 N = normalize(vec3(model * vec4(in_Vertex, 0.0)));
    T = normalize(T - dot(T, N) * N);
    vec3 B = cross(N, T);
    
    mat3 TBN = transpose(mat3(T, B, N));    
    vs_out.TangentLightPos = TBN * lightPos;
    vs_out.TangentViewPos  = TBN * viewPos;
    vs_out.TangentFragPos  = TBN * vs_out.FragPos;
    
}