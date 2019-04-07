<?php

function auth($login, $passwd)
{
	$pw = hash('whirlpool', $passwd);
	$array = file_get_contents("../private/passwd");
	$unseri = unserialize($array);
	foreach ($unseri as $key => $elem)
	{
		if ($elem['login'] == $login && $elem['passwd'] === $pw)
			return (TRUE);
	}
	return (FALSE);
}

?>
