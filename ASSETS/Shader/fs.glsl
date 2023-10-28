#version 330 core
out vec4 FragColor;
  
  in vec2 Texcordinates;
  in vec3 FragPos;
  in vec3 normal;


  uniform vec3 camPos;
  uniform vec3 viewDir;

  struct Material {
    sampler2D texture_diffuse1;
}; 
uniform Material material;

void main()
{
	
 //FragColor = texture(material.texture_diffuse1,Texcordinates);// * vec4(1.0,Texcordinates,1.0);
   //FragColor = vec4(0.0,Texcordinates,1.0);
   FragColor = vec4(0.0,1.0,1.0,1.0);
   
}














//struct DirLight{
//	vec3 direction;
//
//	vec3 ambient;
//	vec3 diffuse;
//	vec3 specular;
//};
//uniform DirLight dirLight;
////point light
//struct PointLight{
//	vec3 position;
//
//	float constant;
//	float linear;
//	float quadratic;
//
//	vec3 ambient;
//	vec3 diffuse;
//	vec3 specular;
//};
//#define NR_POINT_LIGHTS 4
//uniform PointLight pointLights[NR_POINT_LIGHTS];
////spot light
//struct SpotLight{
//	vec3 position;
//    vec3 direction;
//	float cutOff;
//	float outherCutOff;
//
//	float constant;
//	float linear;
//	float quadratic;
//
//    vec3 ambient;
//    vec3 diffuse;
//    vec3 specular;
//};
//uniform SpotLight spotLight;
//
//
//struct Material {
//    sampler2D diffuse;
//    sampler2D specular;
//    float shininess;
//}; 
//uniform Material material;
//
////main uniform
//in vec2 Texcordinates;
//in vec3 normal;
//in vec3 FragPos;
//uniform vec3 viewPos;
//
////light function
//vec3 CalcDirLight(DirLight light,vec3 normal , vec3 viewDir);
//vec3 CalcPointLight(PointLight light,vec3 normal , vec3 fragPos , vec3 viewDir);
//vec3 CalcSpotLight(SpotLight light,vec3 normal , vec3 fragPos , vec3 viewDir);
//
//
//void main(){
//	
//	vec3 norm = normalize(normal);
//	vec3 viewDir = normalize(viewPos - FragPos);
//	
//	vec3 result = CalcDirLight(dirLight,norm,viewDir);
//	
//	for(int i = 0; i < NR_POINT_LIGHTS ; i++){
//	result += CalcPointLight(pointLights[i],norm,FragPos,viewDir);
//	
//	}
//
//	//FragColor = vec4(result,1.0f);
//	FragColor = vec4(Texcordinates,0.0,1.0);
//
//};
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//vec3 CalcDirLight(DirLight light,vec3 normal , vec3 viewDir){
//	vec3 lightDir = normalize(-light.direction);
//
//	float diff = max(dot(normal,lightDir),0.0);
//
//	vec3 reflectDir = reflect(-lightDir,normal);
//	float spec = pow(max(dot(viewDir,reflectDir),0.0),material.shininess);
//
//	vec3 ambient = light.ambient * vec3(texture(material.diffuse,Texcordinates));
//	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse,Texcordinates));
//	vec3 specular = light.specular * spec * vec3(texture(material.specular,Texcordinates));
//	return(ambient + diffuse + specular);
//
//}
//
//vec3 CalcPointLight(PointLight light, vec3 normal , vec3 fragPos , vec3 viewDir){
//	vec3 lightDir = normalize(light.position - fragPos);
//
//	float diff = max(dot(normal,lightDir),0.0);
//
//	vec3 reflectDir = reflect(-lightDir,normal);
//	float spec = pow(max(dot(viewDir,reflectDir),0.0),material.shininess);
//
//	float distance = length(light.position - FragPos);
//    float attenuation = 1.0/(light.constant + light.linear * distance + light.quadratic* (distance * distance));
//
//	vec3 ambient = light.ambient * vec3(texture(material.diffuse,Texcordinates));
//	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse,Texcordinates));
//	vec3 specular = light.specular * spec * vec3(texture(material.specular,Texcordinates));
//
//	ambient *= attenuation;
//	diffuse *= attenuation;
//	specular *= attenuation;
//
//
//	return(ambient + diffuse + specular);
//}
//
//
//
//
//vec3 CalcSpotLight(SpotLight light,vec3 normal , vec3 fragPos , vec3 viewDir){
//
//	vec3 lightDir = normalize(light.position - fragPos);
//
//	float diff = max(dot(normal,lightDir),0.0);
//
//	vec3 reflectDir = reflect(-lightDir,normal);
//	float spec = pow(max(dot(viewDir,reflectDir),0.0),material.shininess);
//
//	float distance = length(light.position - FragPos);
//    float attenuation = 1.0/(light.constant + light.linear * distance + light.quadratic* (distance * distance));
//
//
//	vec3 ambient = light.ambient * vec3(texture(material.diffuse,Texcordinates));
//	vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse,Texcordinates));
//	vec3 specular = light.specular * spec * vec3(texture(material.specular,Texcordinates));
//
//	float theta = dot(lightDir,normalize(-light.direction));
//    float epsilon = (light.cutOff - light.outherCutOff);
//    float intensity = clamp((theta- light.outherCutOff)/epsilon ,0.0,1.0);
//
//    ambient *=attenuation * intensity;
//    diffuse *=attenuation * intensity;
//    specular *= attenuation * intensity;
//
//	
//
//
//	return(ambient + diffuse + specular);
//}



