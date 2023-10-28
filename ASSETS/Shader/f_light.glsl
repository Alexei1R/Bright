#version 330 core
out vec4 FragColor;


//from vertex shader
in vec3 normal;
in vec2 Texcordinates;
in vec3 FragPos;


//
vec3 lightColor = vec3(1.0,1.0,1.0);
vec3 objectColor = vec3(0.05,0.3,0.2);
vec3 lightPos = vec3(1.0,2.0,1.0);

//from user
uniform vec3 viewPos;


//new stuff
in vec3 Normal;
in vec3 Position;

uniform samplerCube skybox;


void  main(){





    vec3 I = normalize(Position - viewPos);
    vec3 R = reflect(I, normalize(Normal));
    vec4 reflectionsky = vec4(texture(skybox, R).rgb, 1.0);










    float ambientStrength = 0.5;
    vec3 ambient = ambientStrength * lightColor;
    
    vec3 norm = normalize(normal);
    vec3 lightDir = normalize(lightPos - FragPos);  
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor;
    
    
    
    
    float specularStrength = 0.5;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);  
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 20);
    vec3 specular = specularStrength * spec * lightColor;
    
    
    
    
    vec3 result = (ambient + diffuse + specular) * objectColor;
    FragColor = mix(vec4(result, 1.0),reflectionsky , 0.5);
    


}



























//  in vec2 Texcordinates;
//  in vec3 FragPos;
//  in vec3 normal;
//
//
//  uniform vec3 camPos;
//  uniform vec3 viewDir;
//  uniform vec3 objectColor ;
//
//
//vec3 lightColor = vec3(1.0f);
//
//vec3 lightPos = vec3(1.0,2.0,2.0);
//float specularStrength = 0.5;
//
//
//void main()
//{
//	float ambientStrength = 0.4;
//    vec3 ambient = ambientStrength * lightColor;
//
//
//    vec3 norm = normalize(normal);
//    vec3 lightDir = normalize(lightPos - FragPos);  
//    float diff = max(dot(norm, lightDir), 0.0);
//    vec3 diffuse = diff * lightColor;
//
//
//    vec3 vDir = normalize(viewDir - FragPos);
//    vec3 reflectDir = reflect(-lightDir, norm);  
//    float spec = pow(max(dot(vDir, reflectDir), 0.0), 32);
//    vec3 specular = specularStrength * spec * lightColor;  
//
//
//
//
//    vec3 result = (ambient + diffuse + specular) * objectColor;
//    FragColor = vec4(result, 1.0);
//   
//}






