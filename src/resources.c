#include <cJSON.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getVertices(char name[], float* buffer, int bufferSize){
        FILE *fp;
	char dirPath[] = "/home/nikola/dev/GL/resources/meshes/";
	char *filePath = strcat(dirPath, name);

        fp = fopen(filePath, "r");
        if (fp == NULL){
		fprintf(stderr, "cannot found file: %s\n", filePath);
                return 1;
	}
	
	char fileBuffer[1024]={0};
        char lineBuffer[128];
        while(fgets(lineBuffer, 128, fp)){
		strcat(fileBuffer, lineBuffer);
		}
	fclose(fp);

	cJSON *data = cJSON_ParseWithLength(fileBuffer, 512);
	if(data == NULL){
		const char *JSONError = cJSON_GetErrorPtr();
		if(JSONError != NULL){
			fprintf(stderr, "Error: %s\n", fileBuffer);
		}
		return 2;
	}
	
	cJSON *array = cJSON_GetObjectItem(data, "vertices");
	if(array == NULL){
		perror("vertices item not found\n");
		return 3;
	}

	int i = 0;
	cJSON *element = array->child;
	while(i < bufferSize && element != NULL){
		*buffer = (float) element->valuedouble;
		element = element->next;
		i++;
		buffer++;
	}

	cJSON_Delete(data);
        return 0;
}

int getShader(char name[], GLuint shaderType, GLunit shaderPointer*){
        FILE *fp;
	char dirPath[] = "/home/nikola/dev/GL/resources/meshes/";
	char *filePath = strcat(dirPath, name);

        fp = fopen(filePath, "r");
        if (fp == NULL){
		fprintf(stderr, "cannot found file: %s\n", filePath);
                return 1;
	}
	
	char *shaderSource[64];
	int lineCount = 0;
	while(lineCount < 64){
		lineBuffer = malloc(128 * sizeof(char));
		if(lineBuffer, 128, fp){
			shaderSource[lineCount++] = lineBuffer;
		} else{
			break;
		}
	}

        while(fgets(lineBuffer, 128, fp)){
		strcat(fileBuffer, lineBuffer);
		}
	 
	fclose(fp);

	shaderPointer = glCreateShader(shaderType);
	glShaderSource(shaderPoiter, lineCount, shaderSource, NULL);
	glCompileShader(shaderPointer);

	int i;
	for(i = 0; i<lineCount; i++){
		free(shaderSource[i];
	}

	GLint success = 0;
	glGetShaderiv(shaderPoiter, GL_COMPILE_STATUS, &success);

	return success;
}

int getShaderError(GLuint shaderPointer*, char* messagePointer){
	GLint 
	}
