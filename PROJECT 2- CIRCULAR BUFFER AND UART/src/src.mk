SOURCES = main.c \

                           circ_buf.c \

                           led_init.c \

                           tx_poll.c \

                           uart_frdm.c\
			
			   unittest.c \

			   unittestwithrand.c	

 

SOURCES_KL25Z = main.c \

                          circ_buf.c \

                           led_init.c \

                           tx_poll.c \

                           uart_frdm.c\
			
			   unittest.c \

			   unittestwithrand.c \

                           system_MKL25Z4.c

 

INCLUDES = -I ../include/common

 

INCLUDES_KL25Z = -I ../include/common \

                   -I ../include/CMSIS \

                   -I ../include/kl25z
