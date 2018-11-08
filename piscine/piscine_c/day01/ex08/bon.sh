ldapsearch cn 2> /dev/null | grep cn: | grep -E "([a-z]+)+ .*BON.*" | wc -l | tr -d ' '
