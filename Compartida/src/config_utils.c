#include "../include/config_utils.h"


t_config* iniciar_config(char* path)
{
    t_config *nuevo_config = config_create(path);

    if (nuevo_config == NULL) {
        fprintf(stderr, "No se pudo iniciar el config: %s\n", path);
        exit(1);
    }

    return nuevo_config;
}
