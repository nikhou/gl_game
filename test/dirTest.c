#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <cJSON.h>
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

int main(){
	char cwd[128];
	if(getcwd(cwd, 128)!=NULL) {
		printf("CWD: %s\n", cwd);
	} else {
		perror("getpwd error");
		return 1;
	}

	float *buffer = malloc(16);
	if(getVertices("triangle.json", buffer, 16) == 0){
		free(buffer);
		return 0;
	} else {
		free(buffer);
		return 1;
	}
}
