#!/bin/bash
cp /opt/gitlab/embedded/cookbooks/runit/files/default/gitlab-runsvdir.conf /etc/init/
cd /opt/gitlab/embedded/bin && ./runsvdir-start &
gitlab-ctl reconfigure
cat /opt/gitlab/embedded/etc/90-omnibus-gitlab-* >> /etc/sysctl.conf
cp -f /home/app/sysctl.rb /opt/gitlab/embedded/cookbooks/package/resources/sysctl.rb
gitlab-ctl reconfigure
gitlab-ctl restart
gitlab-ctl tail
