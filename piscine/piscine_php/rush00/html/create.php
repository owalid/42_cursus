<?php
include('../php/query.php');
function get_categorie(){
	$categories = get_all_categories();
	foreach ($categories as $cat)
	{
		echo '<a href="../php/produits.php?categorie=' . $cat['id_cat'] . '"><li>' . $cat['name_cat'] . '</li></a>';
	}
}
?>
<html>
	<head>
		<meta charset="utf-8">
		<link rel="stylesheet" type="text/css" href="../css/create.css">
		<title>Login</title>
	</head>
	<body>
		<nav role="navigation">
			<div id="menuToggle">
				<input type="checkbox" />
				<span></span>
				<span></span>
				<span></span>
				<ul id="menu">
					<p><a id="name-site" href="../php/checklogin.php">ChaudSet</a></p>
					<?php get_categorie(); ?>
				</ul>
			</div>
		</nav>
		<a href="../index.php"><p>MENU</p></a>
		<div id="login">
		<form method="post" action="../php/create.php">
			<input type="text" name="lastname" id="lastname" required value="" placeholder="LastName">
			<input type="text" name="firstname" id="firstname" required value="" placeholder="FirstName">
			<input type="text" name="login" id="identifiant" minlength="3" maxlength="15" required value="" placeholder="Username">
			<input type="password" name="passwd" id="pwd" minlength="8" maxlength="20" required value="" placeholder="Password"> 
			<input type="text" name="email" id="email" pattern="[a-z0-9._-]+@[a-z0-9._-]{2,}\.[a-z]{2,4}" required value="" placeholder="Email">
			<input type="tel" name="phone" id="phone" pattern="[0]{1}[6-7]{1}[0-9]{8}" required value="" placeholder="Phone">
			<input type="date" name="birth" id="birth" min="1919-03-30" max="2001-03-30" required value="" placeholder="Birthday">
			<input type="submit" name="submit" value="Sign Up">
		</form>
	</div>
	</body>
</html>
