#include "./include/init_kernel.h"


typedef struct {
	char* ip_memoria;
	char* puerto_memoria;
	char* puerto_dispatch;
	char* puerto_interrupt;
} t_config_kernel;

t_config* config;

int main(void) {
	
	//funcion leer/cargar config
	t_config_kernel *config_kernel = malloc(sizeof(t_config_kernel));
	//todo pasar el loger a compartida pendiente
	logger = log_create("kernel.log", "Inicio modulo KERNEL", 1, LOG_LEVEL_DEBUG);

	//TODO leer kernel.config
	config = iniciar_config("./kernel.config");
	config_kernel->ip_memoria = config_get_string_value(config, "IP_MEMORIA");
	config_kernel->puerto_memoria = config_get_string_value(config, "PUERTO_MEMORIA");

	log_info(logger, config_kernel->ip_memoria);
	
	
	//TODO deberia pasar por parametros los valores leidos en kernel.config
	int server_fd = iniciar_servidor(logger, "kernel",config_kernel->ip_memoria, config_kernel->puerto_memoria);
	
	
	log_info(logger, "Kernel esta listo para recibir");



	// Primero, liberar las cadenas de caracteres que se asignaron
free(config_kernel->ip_memoria);   // Se debe liberar la memoria de la cadena asignada
free(config_kernel->puerto_memoria);


// Finalmente, liberar la estructura en sí
free(config_kernel);

log_destroy(logger);

	int cliente_fd = esperar_cliente(server_fd);




	//TODO cambiar a listas que se usara en kernel
	t_list* lista;
	while (1) {
		int cod_op = recibir_operacion(cliente_fd);
		switch (cod_op) {
		case MENSAJE:
			recibir_mensaje(cliente_fd);
			break;
		case PAQUETE:
			lista = recibir_paquete(cliente_fd);
			log_info(logger, "Me llegaron los siguientes valores:\n");
			list_iterate(lista, (void*) iterator);
			break;
		case -1:
			log_error(logger, "el cliente se desconecto. Terminando servidor");
			return EXIT_FAILURE;
		default:
			log_warning(logger,"Operacion desconocida. No quieras meter la pata");
			break;
		}
	}
	return EXIT_SUCCESS;
}

void iterator(char* value) {
	log_info(logger,"%s", value);
}
