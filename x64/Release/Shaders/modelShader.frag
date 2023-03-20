// ============ GLSL version ============
#version 400 core

// ============ In data ============
uniform sampler2D texture_diffuse1;
in vec2 TexCoords;
in vec3 Normal;
in vec3 FragPos;
// uniform bool hdr;
uniform vec3 viewPos;
uniform vec3 sunPos;

// ============ Out data ============
layout (location = 0) out vec4 FragColor;
layout (location = 1) out vec4 BrightColor;

void main()
{
    vec3 lightColor = vec3(1.0);

    vec3 lightPos = sunPos;

    vec3 objectColor = texture(texture_diffuse1, TexCoords).rgb;

    // *********************************************** mitigation ***************************************************
    //mitigation
    // float lightConst = 1.0f;
    // float lightLin = 0.35f;
    // float lightQuad = 0.44f;
    // float distance = length(lightPos - FragPos);
    // float mitigation = 1.0 / (lightConst + lightLin + lightQuad);

    // // *********************************************** diffuse light ***************************************************
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    // *********************************************** specular light ***************************************************
    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 halfwayDir = normalize(lightDir + viewDir);
    float spec = 0.0;
    spec = pow(max(dot(norm, halfwayDir), 0.0), 32);
    vec3 specular = spec * lightColor;

    // *********************************************** ambiant light ***************************************************
    float ambiantStrength = 0.1;

    vec3 ambiant = ambiantStrength * lightColor;

    // *********************************************** adding mitigation effect ***************************************************
    // ambiant *= mitigation;
    // diffuse *= mitigation;
    // specular *= mitigation;
    
    vec3 result = (ambiant + diffuse + specular) * objectColor;
    FragColor = vec4(result, 1.0);
    float brightness = dot(result, vec3(0.2126, 0.7152, 0.0722));
    if(brightness > 1.0)
        BrightColor = vec4(result, 1.0);
    else
        BrightColor = vec4(0.0, 0.0, 0.0, 1.0);
}