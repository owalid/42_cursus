FROM ruby

RUN apt-get update -y && apt-get upgrade -y
RUN gems install rails
RUN apt-get install -y nodejs sqlite3 build-essential libpq-dev

ONBUILD COPY . /opt/app

ONBUILD RUN bundle update && \
bundle install

WORKDIR /opt/app