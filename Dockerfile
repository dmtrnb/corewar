FROM	alpine

RUN	apk update && apk add \
		openssh-server \
		nano \
		emacs \
		git \
		gdb \
		gcc \
		g++ \
		clang \
		make \
		ncurses-dev \
	&& rm -rf /var/cache/apk/*

COPY	./includes /tmp/corewar/includes/
COPY	./libft /tmp/corewar/libft/
COPY	./srcs /tmp/corewar/srcs/
COPY	./players /tmp/corewar/players/
COPY	./Makefile /tmp/corewar/

WORKDIR /tmp/corewar

ENTRYPOINT make && while true; do sleep 1000; done
