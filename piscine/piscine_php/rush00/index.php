<?php
include('php/query.php');
function get_categorie(){
	$categories = get_all_categories();
	foreach ($categories as $cat)
	{
		echo '<a href="php/produits.php?categorie=' . $cat['id_cat'] . '"><li>' . $cat['name_cat'] . '</li></a>';
	}
}
session_start();
if ($_SESSION['loggued_on_user'] == "")
	$logg = 'html/login.html';
else
	$logg = 'html/choice.php';
?>
<html>
	<head>
		<meta charset="utf-8">
		<link rel="stylesheet" type="text/css" href="css/index.css">
		<title>index</title>
	</head>
	<body>
	<nav role="navigation">
		<div id="menuToggle">
			<input type="checkbox" />
			<span></span>
			<span></span>
			<span></span>
			<ul id="menu">
				<p id="bonjour">Bonjour</p>
				<a href="<?php echo $logg ?>"><li>Sign In</li></a>
				<?php get_categorie(); ?>
				<a href="php/panier.php"><li>Panier</li></a>
			</ul>
		</div>
	</nav>
	<p><a id="name-site" href="php/checklogin.php">ChaudSet</a></p>
	<?php $categories = get_all_categories();
	foreach ($categories as $cat)
	{
		echo '<a id="cate" href="php/produits.php?categorie=' . $cat['id_cat'] . '">' . $cat['name_cat'] . '</a><br /><br />';
	} ?>
	</body>
</html>
