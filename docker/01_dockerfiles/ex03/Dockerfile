# https://about.gitlab.com/install/#debian

FROM debian
EXPOSE 80 2200 443 22
RUN apt-get update -y && apt-get upgrade -y
RUN apt-get install -y curl openssh-server ca-certificates
RUN apt-get install -y postfix
RUN curl https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh | bash
RUN EXTERNAL_URL="https://gitlab.example.lcom" 
RUN apt-get install -y gitlab-ce
ENTRYPOINT (/opt/gitlab/embedded/bin/runsvdir-start &) &&  gitlab-ctl reconfigure && gitlab-ctl restart && gitlab-ctl tail
