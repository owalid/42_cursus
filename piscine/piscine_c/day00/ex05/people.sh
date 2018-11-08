ldapsearch  '(uid=z*)' 2> /dev/null | sort --ignore-case --reverse | grep cn: | sed 's/cn: //g'
