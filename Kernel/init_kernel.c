#include "./include/init_kernel.h"

int main(void) {
	
	logger = log_create("kernel.log", "Inicio modulo KERNEL", 1, LOG_LEVEL_DEBUG);

	//TODO leer kernel.config

	//TODO deberia pasar por parametros los valores leidos en kernel.config
	int server_fd = iniciar_servidor();
	
	
	log_info(logger, "Kernel esta listo para recibir");
	
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
