FROM debian
EXPOSE 9987/udp
EXPOSE 10011
EXPOSE 30033
ENV TS3SERVER_LICENSE=accept
RUN apt-get update -y && apt-get upgrade -y && apt-get install tar wget -y
RUN wget http://dl.4players.de/ts/releases/3.0.11.2/teamspeak3-server_linux-amd64-3.0.11.2.tar.gz
RUN tar -zxvf teamspeak3-server_linux-amd64-3.0.11.2.tar.gz
RUN sh teamspeak3-server_linux-amd64/ts3server_startscript.sh start
