// ============ GLSL version ============
#version 400 core

// ============ In data ============
uniform vec3 viewPos;
uniform vec3 sunPos;
uniform vec3 atmoColor;
in vec3 Normal;
in vec3 FragPos;

// ============ Out data ============
layout (location = 0) out vec4 FragColor;
layout (location = 1) out vec4 BrightColor;

void main()
{
    vec3 objectColor = atmoColor;

    vec3 lightColor = vec3(0.5);

    vec3 lightPos = sunPos;

    // // *********************************************** mitigation ***************************************************
    // float lightConst = 1.0f;
    // float lightLin = 0.35f;
    // float lightQuad = 0.44f;
    // float distance = length(lightPos - FragPos);
    // float mitigation = 1.0 / (lightConst + lightLin + lightQuad);

    // *********************************************** diffuse light ***************************************************
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;

    // *********************************************** specular light ***************************************************
    // float specularStrength = 0.5;
    // vec3 viewDir = normalize(viewPos - FragPos);
    // vec3 reflectDir = reflect(-lightDir, norm);
    // float spec = pow(max(dot(viewDir, reflectDir), 0.0), 16);
    // vec3 specular = specularStrength * spec * lightColor;

    // *********************************************** ambiant light ***************************************************
    float ambiantStrength = 0.2;

    vec3 ambiant = ambiantStrength * lightColor;

    // *********************************************** adding mitigation effect ***************************************************
    //ambiant *= mitigation;
    //diffuse *= mitigation;
    //specular *= mitigation;

    // *********************************************** adding diffuse/ambiant light to fragment ***************************************************
    vec3 result = (ambiant + diffuse) * objectColor;

    float min_Transparency = 0.1;

    vec4 trans = max(vec4(0.0), ((vec4(result, 0.2)) - min_Transparency));

    vec3 result2 = vec3(trans.x, trans.y, trans.z);
    FragColor = trans;

    float brightness = dot(result2, vec3(0.2126, 0.7152, 0.0722));
    if(brightness > 0.0)
        BrightColor = vec4(result2, 1.0);
    else
        BrightColor = vec4(0.0, 0.0, 0.0, 1.0);
}